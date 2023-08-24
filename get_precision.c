#include "main.h"

/**
 * get_precision - This calcs the precision use for printing
 * @format: format used on the code 
 * @i: agr list to be printed
 * @args_list: arg list
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list args_list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(args_list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}
