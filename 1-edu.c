#include "main.h"

/**
 * print_decimal - Prints a decimal number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_decimal(va_list types, char buffer[],
		  int flags, int width, int precision, int size)
{
	long int num = va_arg(types, int);
	int is_negative = 0;
	int i = BUFF_SIZE - 2;

	num = convert_size_number(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	if (num < 0)
	{
		num = -num;
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width,\
			     precision, size));
}

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: Get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],\
		 int flags, int width, int precision, int size)
{
	int i;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_decimal}, {'d', print_decimal}, {'\0', NULL}};

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
	if (fmt[*ind] == fmt_types[i].fmt)

	return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	return (0);
}