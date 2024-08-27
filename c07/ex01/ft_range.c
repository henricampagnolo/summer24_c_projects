#include <stdlib.h>
#include <stdio.h>

int *ft_range(int min, int max);

int *ft_range(int min, int max)
{
	int i;
	int* arr;
	int size;
	
	if (min >= max)
		return 0;
	i = 0;
	size = (max - min);
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int main(void)
{
	int *arr;

	arr = ft_range(9, 7);
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ", arr[i]);
	}
}