#include "sort.h"

/**
 * quick_sort - implements a quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper function
 * @array: array to be sorted
 * @low: low number
 * @high: high number
*/
void quick_sort_helper(int *array, int low, int high, size_t size) {
    int pi;

    if (low < high) {
        pi = partition(array, low, high, size);
        quick_sort_helper(array, low, pi - 1, size);
        quick_sort_helper(array, pi + 1, high, size);
    }
}

/**
 * @partition - partition scheme
 * @array: array to be sorted
 * @low: lowest digit
 * @high: highest digit
 * @size: size of the array
 * Return: integer
*/
int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

/**
 * swap - swaps
 * @a: first number
 * @b: Second number
*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}