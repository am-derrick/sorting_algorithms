#include "sort.h"
#include <stdio.h>

/**
 * partition - finds partition using the Lamuto partition scheme
 * @array: array to partition
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: index of partition
 */
ssize_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int tmp, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
		        if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts the partitions
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of int using Quick Sort Algo
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
