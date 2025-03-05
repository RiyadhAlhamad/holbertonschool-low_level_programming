#include "main.h"
/**
 * calculo - hace las  operaciones
 * @a: numero 1
 * @b: numero 2
 *
 * Return: valores
 */
int calculo(int a, int b)
{
	if (b == 1)
	{
		return (1);
	}
	if (a % b == 0)
	{
		return (0);
	}
	return (calculo(a, b - 1));
}
/**
 * is_prime_number - muestra si un numero es primo
 * @n: numero a verificar
 *
 * Return: 1 si, 0 no
 */
int is_prime_number(int n)
{
	if (n < 2)
	{
		return (0);
	}
	return (calculo(n, n - 1));
}
