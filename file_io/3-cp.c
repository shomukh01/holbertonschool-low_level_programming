#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
	* close_file - closes file descriptor
	* @fd: file descriptor
	*/
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
	* copy_file - copies content
	* @fd_from: source
	* @fd_to: destination
	* @file_to: destination name
	* @file_from: source name
	*/
void copy_file(int fd_from, int fd_to, char *file_to, char *file_from)
{
	ssize_t r, w;
	char buffer[1024];

	while ((r = read(fd_from, buffer, 1024)) > 0)
	{
		w = write(fd_to, buffer, r);
		if (w == -1 || w != r)
		{
			close_file(fd_from);
			close_file(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (r == -1)
	{
		close_file(fd_from);
		close_file(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
	* main - cp program
	* @argc: arg count
	* @argv: args
	*
	* Return: 0
	*/
int main(int argc, char **argv)
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_file(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	copy_file(fd_from, fd_to, argv[2], argv[1]);

	close_file(fd_from);
	close_file(fd_to);

	return (0);
}

