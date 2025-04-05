#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: The number to search in
 * @index: The index of the bit to return (starting from 0)
 *
 * Return: Value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	if ((n >> index) & 1)
		return (1);
	else
		return (0);
}
