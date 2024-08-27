#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int ft_strlen(char* str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void ft_strcat(char *dest, char *src)
{
	int dest_len;
	int i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != 0)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int i;
	int total_size;
	int sep_size;
	char *result;
	char *emptysrt;

	emptysrt = malloc(sizeof(char));
	*emptysrt = '\0';
	if (size == 0)
		return emptysrt;
	sep_size = ft_strlen(sep);
	i = 0;
	total_size = -sep_size + 1;
	while (i < size)
		total_size += ft_strlen(strs[i++]) + sep_size;
	result = malloc(sizeof(char) * total_size);
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i < size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	printf("We joined all the strings with new lines: %s", ft_strjoin(argc, argv, "\n: "));
}