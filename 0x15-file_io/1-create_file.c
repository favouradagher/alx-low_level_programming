#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_file - Creates a file and writes content to it
 *
 * @filename: Name of the file to create
 * @text_content: NULL terminated string to write to file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, res = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;

		res = write(fd, text_content, len);
		if (res == -1)
			return (-1);
	}

	close(fd);
	return (1);
}

