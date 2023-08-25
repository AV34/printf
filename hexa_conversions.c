#include "main.h"

/**
 * print_hexadecimal - prints hexadecimal number 
 * @types: arguments list
 * @buffer: Buffer []
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars to be printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Unsigned hex upper number printing
 * @types: argument list
 * @buffer: Buffer array
 * @flags: active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars to be printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hex - prints haxadecimal in lower or upper form
 * @types: argument list
 * @map_to: [] values to map num
 * @buffer: Buffer []
 * @flags:  active flags
 * @flag_ch: checks active flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of chars to be printed.
 */
int print_hex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}

	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
