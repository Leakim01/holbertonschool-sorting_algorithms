#include "sort.h"
/**
 * _swap - swap two numbers.
 * @a: integer
 * @b: integer
 **/

void _swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * backward_insertion -swap two nodes right left position
 * @array: array
 * @gap: gap
 * @act: actual position in the array
 **/
void backward_insertion(int *array, int gap, int act)
{
	int i;

	for (i = act - gap; i >= 0; i -= gap, act -= gap)
	{
		if (array[i] > array[act])
			_swap(&array[i], &array[act]);
		else
			break;
	}
}
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int flag = 0, gap = 1, i, j;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = 0, j = gap; j < size; i++, j++)
		{
			if (array[i] > array[j])
			{
				_swap(&array[i], &array[j]);
				backward_insertion(array, gap, i);
				flag = 1;
			}
		}
		if (flag == 1)
		{
			print_array(array, size);
			flag = 0;
		}
		gap /= 3;
	}
}
