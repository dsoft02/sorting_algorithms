#include "sort.h"

/**
* getMaxDigit - Search the max of an array
*
* @array: The given array
* @size: The size
*
* Return: The max
*/
int getMaxDigit(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
* radixSort - Sort the array by the digit
*
* @array: Array to be sorted
* @buf: Buffer of the array, to make opération in before
*       put all the content back into the array parent
* @size: Size of the array
* @digit: The digit to look
*
* Return: Anything, cause void function
*/
void radixSort(int *array, int *buf, size_t size, size_t digit)
{
	size_t i;
	int arrayCount[10];

	for (i = 0; i < 10; i++)
		arrayCount[i] = 0;

	for (i = 0; i < size; i++)
		arrayCount[(array[i] / digit) % 10]++;

	for (i = 1; i < 10; i++)
		arrayCount[i] += arrayCount[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buf[arrayCount[(array[i] / digit) % 10] - 1] = array[i];
		arrayCount[(array[i] / digit) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buf[i];
}

/**
* radix_sort - Sort an array using the radix sort
* methode
*
* @array: The array to sort
* @size: The size of the array
*
* Return: Anything, cause void function
*/
void radix_sort(int *array, size_t size)
{
	size_t max, i;
	int *buf;

	if (!array || size <= 1)
		return;

	max = getMaxDigit(array, size);

	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	for (i = 1; max / i > 0; i *= 10)
	{
		radixSort(array, buf, size, i);
		print_array(array, size);
	}
	free(buf);
}
