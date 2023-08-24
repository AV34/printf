#include "main.h"
/**
 * print_percent - char printing
 * @types: arg listing
 * @buffer: A buffer [] to handle printing
 * @flags:  calc active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: num of char printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
