#include "sort.h"

int get_max(int *arr, int s);
void radix_counting_sort(int *arr, size_t s, int sig, int *buff);
void radix_sort(int *arr, size_t s);

/**
 * get_max - Get the maximum value in an arr of integers.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 *
 * Return: The maximum integer in the arr.
 */
int get_max(int *arr, int s)
{
	int max, i;

	for (max = arr[0], i = 1; i < s; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}

	return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an arr of integers
 *                       in ascending order using the counting sort algorithm.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted arr.
 */
void radix_counting_sort(int *arr, size_t s, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < s; i++)
		count[(arr[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = s - 1; (int)i >= 0; i--)
	{
		buff[count[(arr[i] / sig) % 10] - 1] = arr[i];
		count[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < s; i++)
		arr[i] = buff[i];
}

/**
 * radix_sort - Sort an arr of integers in ascending
 *              order using the radix sort algorithm.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the arr after each significant digit increase.
 */
void radix_sort(int *arr, size_t s)
{
	int max, sig, *buff;

	if (arr == NULL || s < 2)
		return;

	buff = malloc(sizeof(int) * s);
	if (buff == NULL)
		return;

	max = get_max(arr, s);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(arr, s, sig, buff);
		print_array(arr, s);
	}

	free(buff);
}
