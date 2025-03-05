#include "main.h"
/**
 * _pow_recursion - eleva un nums a la potencia indicada
 * @x: base
 * @y: exponente
 *
 * Return: resultado o -1 si hay error
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	if (y == 0)
	{
		return (1);
	}
	return (x * _pow_recursion(x, y - 1));
}
