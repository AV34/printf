#include "main.h"
/**
 * getprint_handler - prints an argument to format
 * @fmt: format
 * @args_list: arg list for printing
 * @index: index
 * @buffer: Buffer array
 * @flags: calculate active flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: 1 / 2;
 */
int getprint_handler(const char *fmt, int *index, va_list args_list,
		char buffer[], int flags, int width, int precision, int size)
{
	int i, len = 0, print_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*index] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args_list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		len += write(1, &fmt[*index], 1);
		return (len);
	}
	return (print_chars);
}
