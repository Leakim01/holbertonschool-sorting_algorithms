#include "sort.h"
/**
 * _swap - swap two numbers
 * @array: array
 * @a: integer
 * @b: integer
 **/
void _swap(int *array, int a, int b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				_swap(array, i, j);
				print_array(array, size);
			}
		}
	}

}
