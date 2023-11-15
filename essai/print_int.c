#include "main.h"

/**
 * print_int_recursive - Helper function to print integer recursively
 * @n: The integer to print
 * @char_count: Pointer to the character count
 */
void print_int_recursive(int n, int *char_count)
{
	char digit;

	if (n == 0)
		return;

	print_int_recursive(n / 10, char_count);
	digit = '0' + n % 10;
	_putchar(digit, char_count);
}

/**
 * print_int - Print a non-negative integer to standard output
 * @n: The integer to print
 * @char_count: Pointer to the character count
 */
void print_int(int n, int *char_count)
{
	if (n == 0)
	{
		_putchar('0', char_count);
	}
	else if (n < 0)
	{
		_putchar('-', char_count);
		print_int_recursive(-n, char_count);
	}
	else
	{
		print_int_recursive(n, char_count);
	}
}
/**
 * print_binary - Print an unsigned integer in binary format
 * @n: The unsigned integer to print
 * @char_count: Pointer to the character count
 */

void print_binary(unsigned int n, int *char_count)
{
	int i;
	int _zeros = 1;  /* zeros */

	for (i = 31; i >= 0; i--)
	{
		if (((n >> i) & 1) || !_zeros)
		{
			_putchar(((n >> i) & 1) + '0', char_count);
			_zeros = 0;  /* no longer used */
		}
	}

	/* If the integer was 0, print a single 0 */
	if (_zeros)
	{
		_putchar('0', char_count);
	}
}
