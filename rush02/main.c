#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define malloc(x) NULL

int get_size_file(char *file_name)
{
	int size;
	int attemp_size;
	int fd;
	char *file;

	attemp_size = 500;
	size = attemp_size;
	while (size == attemp_size)
	{
		fd = open(file_name, O_RDONLY);
		if (fd == -1)
			return (-1);
		file = malloc(sizeof(char) * attemp_size);
		if (file == 0)
			return (-1);
		size = read(fd, file, attemp_size);
		if (size == attemp_size)
		{
			attemp_size *= 2;
			size = attemp_size;
		}
		free(file);
		close(fd);
	}
	return (size);
}

int main(int argc, char **argv)
{
	char *file;
	int size;
	int fd;

	if (argc != 1)
		return (1);
	size = get_size_file("numbers.dict");
	if (size == -1)
		return (1);
	printf("Size is: %d\n", size);
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (1);
	file = malloc(sizeof(char) * size);
	if (file == 0)
		return (1);
	read(fd, file, size);
	printf("Size is: %d\n", size);
	printf("Content is: %s\n", file);
	free(file);
}