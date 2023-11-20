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

	if (size < 2)
		print_array(array, size);
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < (size - 1); j++)
			{
				if (array[j] < array[j+1])
				{
					swap = true;
					temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
				}
				else
					swap = false;
				if (swap)
					print_array(array, size);
			}
		}
	}
}
