#include "main.h"

/**
 * print_rot13string - prints a rot13'ed string
 * @types: argument list
 * @buffer: Buffer []
 * @flags: checks for active flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: chars to be printed.
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int x, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (x = 0; str[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == str[x])
			{
				a = out[y];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			a = str[x];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
