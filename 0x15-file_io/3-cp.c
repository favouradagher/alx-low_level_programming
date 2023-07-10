#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with a specific status code.
 * @status: The exit status code.
 * @msg: The error message format string.
 * @...: Additional arguments for the format string.
 */
void error_exit(int status, const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	dprintf(STDERR_FILENO, "Error: ");
	vdprintf(STDERR_FILENO, msg, args);
	dprintf(STDERR_FILENO, "\n");
	va_end(args);
	exit(status);
}

/**
 * cp - Copies the content of one file to another.
 * @file_from: The source file.
 * @file_to: The destination file.
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (file_from == NULL || file_to == NULL)
		error_exit(97, "Usage: cp file_from file_to\n");

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1)
		error_exit(99, "Error: Can't write to file %s\n", file_to);

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			error_exit(99, "Error: Can't write to file %s\n", file_to);
	}

	if (bytes_read == -1)
		error_exit(98, "Error: Can't read from file %s\n", file_from);

	if (close(fd_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", fd_to);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	cp(argv[1], argv[2]);

	return (0);
}

