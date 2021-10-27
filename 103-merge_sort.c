#include "sort.h"

/**
 * topdown_merge - sorts and merges mini arrays in src
 * @src: source array
 * @dest: destination to copy array
 * @begin: beeginning index of left split array
 * @middle: middle index of src, end of left array and beginning
 * of right array
 * @end: ending of right split array
 *
 * Return: void
 */
void topdown_merge(int *src, size_t begin, size_t middle, size_t end, int *dest)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(src + begin, middle - begin);
	printf("[right]]: ");
	print_array(src + middle, end - middle);
	i = begin;
	j = middle;
	for (k = begin; k < end; k++)
	{
		if (i > middle && (j >= end || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + begin, end - begin);
}

/**
 * topdown_splitmerge - splits an array and merges the sorted array
 * @array: array to sort
 * @begin: beginning of array
 * @end: end of array
 * @new:new copied array
 *
 * Return: void
 */
void topdown_splitmerge(int *new, size_t begin, size_t end, int *array)
{
	size_t middle;

	if (end - begin < 2)
		return;
	middle = (begin + end) / 2;
	topdown_splitmerge(array, begin, middle, new);
	topdown_splitmerge(array, middle, end, new);
	topdown_merge(new, begin, middle, end, array);
	for (middle = begin; middle < end; middle++)
		new[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of int using Merge Sort Algo
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *new;

	if (array == NULL || size < 2)
		return;
	new = malloc(sizeof(int) * size);
	if (new == NULL)
		return;
	for (i = 0; i < size; i++)
		new[i] = array[i];
	topdown_splitmerge(new, 0, size, array);
	free(new);
}
