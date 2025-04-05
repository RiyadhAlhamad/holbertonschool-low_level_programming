#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

/**
 * main - Copy the content of a file to another file
 *
 * @argc: The number of arguments passed to the program
 * @argv: Array of arguments
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int from,to,r,w;
	char buffer[1024];
	ssize_t n_read,n_written;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,"Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(argv[1],O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't read from file %s\n",argv[1]);
		exit(98);
	}
	to = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
	if (to == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't write to %s\n",argv[2]);
		close(from);
		exit(99);
	}
	while ((n_read = read(from,buffer,1024)) > 0)
	{
		n_written = write(to,buffer,n_read);
		if (n_written == -1)
		{
			dprintf(STDERR_FILENO,"Error: Can't write to %s\n",argv[2]);
			close(from);
			close(to);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't read from file %s\n",argv[1]);
		close(from);
		close(to);
		exit(98);
	}
	if (close(from) == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't close fd %d\n",from);
		exit(100);
	}
	if (close(to) == -1)
	{
		dprintf(STDERR_FILENO,"Error: Can't close fd %d\n",to);
		exit(100);
	}
	return (0);
}
