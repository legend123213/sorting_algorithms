#include "sort.h"

void merge_subarr(int *s_arr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *s_arr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @s_arr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *s_arr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(s_arr + front, mid - front);

	printf("[right]: ");
	print_array(s_arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (s_arr[i] < s_arr[j]) ? s_arr[i++] : s_arr[j++];
	for (; i < mid; i++)
		buff[k++] = s_arr[i];
	for (; j < back; j++)
		buff[k++] = s_arr[j];
	for (i = front, k = 0; i < back; i++)
		s_arr[i] = buff[k++];

	printf("[Done]: ");
	print_array(s_arr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @s_arr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *s_arr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(s_arr, buff, front, mid);
		merge_sort_recursive(s_arr, buff, mid, back);
		merge_subarr(s_arr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
