#include "main.h"

/**
 * _printf - this is for printf
 * @format: format
 * Return: chara_print
 * chara_print - this is for char print
 */

int _printf(const char *format, ...)
{
	int chara_print = 0;
	va_list list_of_args;

	if (format == NULL)
		return (-1);

	va_start(list_of_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{

				char c = va_arg(list_of_args, int);

				write(1, &c, 1);
				chara_print++;
			}
		}
		format++;
	}
	va_end(list_of_args);
	return (chara_print);
}
