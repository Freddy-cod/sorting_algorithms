#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The lowest index of the partition to be sorted
 * @high: The highest index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: The lowest index of the partition
 * @high: The highest index of the partition
 * @size: The size of the array
 *
 * Return: Index of the pivot element after partitioning
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);
    return (i + 1);
}
