#include "main.h"
/**
 * factorial - devuelve el factor de nums dados
 * @n: numero
 *
 * Return: -1 error o factores
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	if (n <= 1)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}
