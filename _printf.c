#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
* _printf - function that prints output to format
* @format: character format
* Return: printed characters on success
*/
int _printf(const char *format, ...)
{
	int i, print_char = 0, print_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/*write(1, &format[i], 1);*/
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args_list);
			precision = get_precision(format, &i, args_list);
			size = get_size(format, &i);
			++i;
			print_char = getprint_handler(format, &i, args_list,
					buffer, flags, width, precision, size);
			if (print_char == -1)
				return (-1);
			print_chars += print_char;
		}
	}
	print_buffer(buffer, &buff_index);
	va_end(args_list);
	return (print_chars);
}

/**
* print_buffer - to print buffer
* @buffer: character array
* @buff_index: array index and length
*/
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
