#include "main.h"
/**
 * _strlen_recursion - cuenta largo de cadena
 * @s: puntero
 *
 * Return: largo de cadena
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}
	return (1 + _strlen_recursion(s + 1));
}
