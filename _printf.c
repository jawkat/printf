#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int char_count = 0; // Initialize the character count
    va_list args; // Declare a variable list to hold the variable arguments

    va_start(args, format); // Start processing the variable arguments

    while (*format != '\0')
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            int num = va_arg(args, int);
            char_count += print_int(num);
            format += 2; // Move to the next format specifier
        }
        else
        {
            _putchar(*format, &char_count);
            format++;
        }
    }

    va_end(args); // End processing the variable arguments

    return char_count; // Return the total number of characters printed
}

/**
 * print_int - Print an integer to standard output
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_int(int n)
{
    if (n == 0)
    {
        _putchar('0', NULL);
        return 1;
    }
    else if (n < 0)
    {
        _putchar('-', NULL);
        return print_int_recursive(-n);
    }
    else
    {
        return print_int_recursive(n);
    }
}

/**
 * print_int_recursive - Helper function to print integer recursively
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_int_recursive(int n)
{
    if (n == 0)
        return 0;

    int count = 1 + print_int_recursive(n / 10);

    _putchar('0' + n % 10, NULL);

    return count;
}
