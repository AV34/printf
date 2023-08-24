#include "main.h"

/**
 * Unsigned num printing
 */

/**
 * print_unsigned - Unsigned number printing
 * @types: agr list
 * @buffer: Buffer [] to handle printing
 * @flags: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars to be printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * Unsigned octal num printing
 */

/**
 * print_octal - Unsigned octal number printing
 * @types: agr list
 * @buffer: Buffer [] to handle printing
 * @flags: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars to be printed.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * Unsigned hex num printing
 */

/**
 * print_hexadecimal - Unsigned hex number printing
 * @types: agr list
 * @buffer: Buffer [] to handle printing
 * @flags: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars to be printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * Unsigned upper hex num printing
 */

/**
 * print_hexa_upper - Unsigned hex upper number printing
 * @types: agr list
 * @buffer: Buffer [] to handle printing
 * @flags: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars to be printed.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * Unsigned hex num in lower or uppoer case printing
 */

/**
 * print_hexa - hex num in low or upper printing Prints
 * @types: agr list
 * @map_to: [] of values to map num
 * @buffer: Buffer [] to handle printing
 * @flags:  cals active flags
 * @flag_ch: cals active flags
 * @width: width
 * @precision: Precision
 * @size: Size specifier
 * @SIZE: Size specification
 * Return: Number of chars to be printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
