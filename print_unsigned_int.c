#include "main.h"

/**
 * print_unsigned - function for unsigned number printing
 * @types: argument list
 * @buffer: Buffer []
 * @flags: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars to be printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 10) + '0';
		num /= 10;
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
