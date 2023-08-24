#include "main.h"

/**
 * Char Printing
 */

/**
 * print_char - char printing for the project
 * @types: arg listing
 * @buffer: A buffer [] to handle printing
 * @flags:  calc active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of char printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (write_char(c, buffer, flags, width, precision, size));
}
