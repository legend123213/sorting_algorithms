#include "sort.h"

void swap_ints(int *x, int *y);
void bitonic_merge(int *arr, size_t s, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *arr, size_t s, size_t start, size_t seq, char flow);
void bitonic_sort(int *arr, size_t s);

/**
 * swap_ints - Swap two integers in an arr.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bitonic_merge - Sort x bitonic sequence inside an arr of integers.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 * @start: The starting index of the sequence in arr to sort.
 * @seq: The s of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *arr, size_t s, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && arr[i] > arr[i + jump]) ||
			    (flow == DOWN && arr[i] < arr[i + jump]))
				swap_ints(arr + i, arr + i + jump);
		}
		bitonic_merge(arr, s, start, jump, flow);
		bitonic_merge(arr, s, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an arr of integers into x bitonic sequence.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 * @start: The starting index of x block of the building bitonic sequence.
 * @seq: The s of x block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *arr, size_t s, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, s, str);
		print_array(arr + start, seq);

		bitonic_seq(arr, s, start, cut, UP);
		bitonic_seq(arr, s, start + cut, cut, DOWN);
		bitonic_merge(arr, s, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, s, str);
		print_array(arr + start, seq);
	}
}

/**
 * bitonic_sort - Sort an arr of integers in ascending
 *                order using the bitonic sort algorithm.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 *
 * Description: Prints the arr after each swap. Only works for
 * s = 2^k where k >= 0 (ie. s equal to powers of 2).
 */
void bitonic_sort(int *arr, size_t s)
{
	if (arr == NULL || s < 2)
		return;

	bitonic_seq(arr, s, 0, s, UP);
}
