
#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *src);

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

void ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char *ft_strdup(char *src)
{
	int srclen;
	char *cpystr;

	srclen = ft_strlen(src);
	cpystr = malloc(sizeof(char) * (srclen + 1));
	ft_strcpy(cpystr, src);
	return (cpystr);
}

int main(void)
{
	char *sentence = "Hello world!";
	char *sentencecpy;

	sentencecpy = ft_strdup(sentence);
	sentencecpy[3] = 'L';
	printf("Og string : %s\nNew string : %s", sentence, sentencecpy);
}