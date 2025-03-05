#include "main.h"
/**
 * calculo - calcula la raiz cuadrada
 * @n: numero
 * @b: bajo
 * @a: alto
 *
 * Return: valor
 */
long calculo(long n, long b, long a)
{
	long mid = b + (a - b) / 2;

	if (mid * mid == n)
	{
		return (mid);
	}
	if (b > a)
	{
		return (-1);
	}
	if (mid * mid > n)
	{
		return (calculo(n, b, mid - 1));
	}
	else
	{
		return (calculo(n, mid + 1, a));
	}
}
/**
 * _sqrt_recursion - devuelve la raiz cuadrada
 * @n: numero
 *
 * Return: resultado
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (calculo(n, 0, n));
}
