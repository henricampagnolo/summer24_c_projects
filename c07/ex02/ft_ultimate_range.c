#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	
	if (min >= max)
	{
		*range = 0;
		return 0;
	}
	i = 0;
	size = (max - min);
	*range = malloc(sizeof(int) * size);
	while (i < size)
	{
		range[0][i] = min + i;
		i++;
	}
	return (size);
}

int main(void)
{
	int *arr;
	int size;

	size = ft_ultimate_range(&arr, -2, 7);
	for (int i = 0; i < size; i++)
	{
		printf("%d, ", arr[i]);
	}
}