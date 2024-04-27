#include "sort.h"
/**
 * bubble_sort - sorts array using bubble sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	bool swap;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		swap = false;
		for (j = 0; j < (size - i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		if (swap == false)
			break;
	}
}
