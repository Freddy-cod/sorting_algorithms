#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max;
	int *count_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc((max + 1) * sizeof(int));
	if (count_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]]++;

	/* Print counting array */
	printf("Counting array:\n");
	for (i = 0; i <= max; i++)
	{
		printf("%d", count_array[i]);
		if (i < max)
			printf(", ");
	}
	printf("\n");

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = (int)size - 1; i >= 0; i--)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(count_array);
	free(sorted_array);
}
