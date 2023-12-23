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
 * bubble_sort - Sort an arr of integers in ascending order.
 * @arr: An arr of integers to sort.
 * @size: The size of the arr.
 *
 * Description: Prints the arr after each swap.
 */
void bubble_sort(int *arr, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (arr == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap_ints(arr + i, arr + i + 1);
				print_array(arr, size);
				bubbly = false;
			}
		}
		len--;
	}
}
