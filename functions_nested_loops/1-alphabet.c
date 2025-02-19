#include "main.h"
/**
 * print_alphabet - prints the alphabet in lowercase, followed by a new line.
 */
void print_alphabet(void)
{
	char lit;

	for (lit = 'a' ; lit <= 'z' ; lit++)
		_putchar(lit);
	_putchar("\n");
}
