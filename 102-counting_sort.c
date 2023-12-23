#include "sort.h"

/**
 * get_maxium - Get the maximum value in an arr of integers.
 * @arr: An arr of integers.
 * @si: The si of the arr.
 *
 * Return: The maximum integer in the arr.
 */
int get_maxium(int *arr, int si)
{
	int max, i;

	for (max = arr[0], i = 1; i < si; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an arr of integers in ascending order
 *                 using the counting sort algorithm.
 * @arr: An arr of integers.
 * @si: The si of the arr.
 *
 * Description: Prints the counting arr after setting it up.
 */
void counting_sort(int *arr, size_t si)
{
	int *count, *sorted, max, i;

	if (arr == NULL || si < 2)
		return;

	sorted = malloc(sizeof(int) * si);
	if (sorted == NULL)
		return;
	max = get_maxium(arr, si);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)si; i++)
		count[arr[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)si; i++)
	{
		sorted[count[arr[i]] - 1] = arr[i];
		count[arr[i]] -= 1;
	}

	for (i = 0; i < (int)si; i++)
		arr[i] = sorted[i];

	free(sorted);
	free(count);
}
