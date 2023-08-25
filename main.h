#ifndef MAIN_H_
#define MAIN_H_
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * This are the Flags section
 */

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * This are the Sizes section
 */

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - This is for Struct
 * @fmt: format specifiers.
 * @fn: This is for func.
 */

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - This is for Struct
 * @fmt: format specifiers
 * @fm_t: This is for func
 */

typedef struct fmt fmt_t;

void print_buffer(char buffer[], int *buff_index);
int _printf(const char *format, ...);
int getprint_handler(const char *fmt, int *i,
va_list args_list, char buffer[], int flags, int width, int precision, int size);

/**
 * This is Functions section
 */

/**
 * Funcs for printing chars and strs
 * @flags: flag
 * @width: width
 * @precision: precision
 * @size: size
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/**
 * Funcs for printing nums
 * @flags: flag
 * @width: width
 * @precision: precision
 * @size: size
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/**
 * Funcs for printing non-printable chars
 * @flags: flag
 * @width: width
 * @precision: precision
 * @size: size
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/**
 * Funcs for handling others specifiers
 */

int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args_list);
int get_precision(const char *format, int *i, va_list args_list);
int get_size(const char *format, int *i);

/**
 * Funcs for printing mem addr
 */

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/**
 * Funcs for printing str in rot 13
 */

int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/**
 * Funcs for printing str in reverse
 */

int print_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/**
 * Section of width handlers
 * @flags: flag
 * @width: width
 * @precision: precision
 * @size: size
 * @buffer: buffer
 */

int write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
int flags, int width, int precision, int size);
int write_num(int index, char buffer[], int flags, int width, int precision,
int length, char padding, char extra_c);
int write_pointer(char buffer[], int index, int length,
int width, int flags, char padding, char extra_c, int padding_start);

int write_unsgnd(int is_negative, int index,
char buffer[],
	int flags, int width, int precision, int size);

/**
 * Section of Utils handlers
 */

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
