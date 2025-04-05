#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"

/**
 * open_file - opens a file
 * @filename: name of the file
 *
 * Return: file descriptor on success, -1 on failure
 */
int open_file(const char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (-1);

    return (fd);
}

/**
 * read_file - reads content from a file
 * @fd: file descriptor
 * @letters: number of letters to read
 * @buffer: buffer to store the read content
 *
 * Return: number of bytes read, or 0 if failed
 */
ssize_t read_file(int fd, size_t letters, char *buffer)
{
    ssize_t bytes_read;

    bytes_read = read(fd, buffer, letters);
    if (bytes_read == -1)
        return (0);

    return (bytes_read);
}

/**
 * write_to_stdout - writes content to standard output
 * @buffer: content to be written
 * @bytes_read: number of bytes to write
 *
 * Return: number of bytes written, or 0 if failed
 */
ssize_t write_to_stdout(char *buffer, ssize_t bytes_read)
{
    ssize_t bytes_written;

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read)
        return (0);

    return (bytes_written);
}

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of the file to read
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print, or 0 if an error occurs
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    fd = open_file(filename);
    if (fd == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(fd);
        return (0);
    }

    bytes_read = read_file(fd, letters, buffer);
    if (bytes_read == 0)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    bytes_written = write_to_stdout(buffer, bytes_read);
    if (bytes_written == 0)
    {
        free(buffer);
        close(fd);
        return (0);
    }

    free(buffer);
    close(fd);

    return (bytes_written);
}
