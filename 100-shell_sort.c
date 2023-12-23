#include "sort.h"

/**
 * swap_ints - Swap two integers in an arr.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an arr of integers in ascending
 *              order using the shell sort algorithm.
 * @arr: An arr of integers.
 * @si: The si of the arr.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *arr, size_t si)
{
	size_t gap, i, j;

	if (arr == NULL || si < 2)
		return;

	for (gap = 1; gap < (si / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < si; i++)
		{
			j = i;
			while (j >= gap && arr[j - gap] > arr[j])
			{
				swap_ints(arr + j, arr + (j - gap));
				j -= gap;
			}
		}
		print_array(arr, si);
	}
}
