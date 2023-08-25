#include "main.h"

/**
 * print_reverse - function that prints a reversed string
 * @types: argument list
 * @buffer: Buffer []
 * @flags: checks active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars to be printed.
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int x, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char y = str[x];

		write(1, &y, 1);
		count++;
	}
	return (count);
}
