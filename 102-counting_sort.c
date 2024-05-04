#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Create and initialize the counting array */
    int *counting_array = malloc((max + 1) * sizeof(int));
    if (counting_array == NULL)
        return;
    for (int i = 0; i <= max; i++)
        counting_array[i] = 0;

    /* Count the occurrences of each element in the array */
    for (size_t i = 0; i < size; i++)
        counting_array[array[i]]++;

    /* Print the counting array */
    printf("Counting array:");
    for (int i = 0; i <= max; i++)
        printf(" %d", counting_array[i]);
    printf("\n");

    /* Update the counting array to contain the actual position of each element */
    for (int i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a temporary array to store the sorted elements */
    int *temp_array = malloc(size * sizeof(int));
    if (temp_array == NULL)
    {
        free(counting_array);
        return;
    }

    /* Sort the array based on the counting array */
    for (int i = size - 1; i >= 0; i--)
    {
        temp_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (size_t i = 0; i < size; i++)
        array[i] = temp_array[i];

    /* Free dynamically allocated memory */
    free(counting_array);
    free(temp_array);
}
