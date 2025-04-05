#include "main.h"
#include <stdlib.h>
#include <fcntl.h>

/**
 * read_textfile - reads a textfile
 * @filename: file to read
 * @letters: amount of bytes to read
 * Return: printed letters count
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t printed, wrote;
	char *buff;

	if (filename == NULL)
		return (0);
	buff = malloc(letters);
	if (buff == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buff);
		return (0);
	}
	printed = read(fd, buff, letters);
	if (printed == -1)
	{
		free(buff);
		close(fd);
		return (0);
	}
	wrote = write(STDOUT_FILENO, buff, printed);
	free(buff);
	close(fd);
	return (wrote == -1 ? 0 : printed);
}
