#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

/**
 * error_exit - Print error message and exit with specified status code
 * @status: The exit status code
 * @msg: The error message format
 * @...: Additional arguments for the error message
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
 * cp - Copy the content of one file to another
 * @file_from: The source file path
 * @file_to: The destination file path
 */
void cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, n;
	char buffer[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
		error_exit(98, "Can't read from file %s", file_from);

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit(99, "Can't write to %s", file_to);

	while ((n = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		if (write(fd_to, buffer, n) != n)
			error_exit(99, "Can't write to %s", file_to);
	}

	if (n == -1)
		error_exit(98, "Can't read from file %s", file_from);

	if (close(fd_from) == -1)
		error_exit(100, "Can't close fd %d", fd_from);

	if (close(fd_to) == -1)
		error_exit(100, "Can't close fd %d", fd_to);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, other values on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return 97;
	}

	cp(argv[1], argv[2]);

	return 0;
}

