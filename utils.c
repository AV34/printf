#include "main.h"

/**
 * is_printable - This determin if a char is to be printed
 * @c: Char to be determin
 * Return: 1 for printale c, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - This append ASCCI in hex code to buffer
 * @buffer: [] of chars.
 * @i: This is the Index at which to start apped.
 * @ascii_code: ASSCI CODE.
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - This is verifcation if char is a digit
 * @c: Char varifcaition
 * Return: 1 for digit as c, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - This casts a num to the size specified
 * @num: num to be casted.
 * @size: num indicating the type to be casted.
 * Return: num value casted
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: num to be casted
 * @size: num indicating the type to be casted
 * Return: num value casted
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
