#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *arr, size_t s, size_t b, size_t root);
void heap_sort(int *arr, size_t s);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @arr: An arr of integers representing a binary tree.
 * @s: The s of the arr/tree.
 * @b: The index of the b row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *arr, size_t s, size_t b, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < b && arr[left] > arr[large])
		large = left;
	if (right < b && arr[right] > arr[large])
		large = right;

	if (large != root)
	{
		swap_ints(arr + root, arr + large);
		print_array(arr, s);
		max_heapify(arr, s, b, large);
	}
}

/**
 * heap_sort - Sort an arr of integers in ascending
 *             order using the heap sort algorithm.
 * @arr: An arr of integers.
 * @s: The s of the arr.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the arr after each swap.
 */
void heap_sort(int *arr, size_t s)
{
	int i;

	if (arr == NULL || s < 2)
		return;

	for (i = (s / 2) - 1; i >= 0; i--)
		max_heapify(arr, s, s, i);

	for (i = s - 1; i > 0; i--)
	{
		swap_ints(arr, arr + i);
		print_array(arr, s);
		max_heapify(arr, s, i, 0);
	}
}
