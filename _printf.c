#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable arguments
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    int char_count = 0; /* Initialize the character count */
    va_list args; /* Declare a variable list to hold the variable arguments */

    va_start(args, format); /* Start processing the variable arguments */
    _format(format, args, &char_count); /* Call the _format function to process the format string */
    va_end(args); /* End processing the variable arguments */

    return char_count; /* Return the total number of characters printed */
}
