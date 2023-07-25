#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to write
 * Return: On success, returns the number of characters written.
 * On error, returns -1.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _print_number - Prints a number using _putchar
 * @n: The number to be printed
 * Return: The number of characters printed
 */
int _print_number(int n)
{
	int count = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10 != 0)
		count += _print_number(n / 10);

	_putchar('0' + n % 10);
	count++;

	return count;
}

/**
 * _print_binary - Prints an unsigned integer in binary format
 * @n: The number to be printed
 * Return: The number of characters printed
 */
int _print_binary(unsigned int n)
{
	int count = 0;
	unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);
	int flag = 0;

	while (mask)
	{
	if (n & mask)
	{
		_putchar('1');
		count++;
		flag = 1;
        }
        else if (flag)
        {
		_putchar('0');
		count++;
        }
        mask >>= 1;
	}

	if (count == 0)
	{
		_putchar('0');
		count++;
	}

	return count;
}

/**
 * _print_unsigned - Prints an unsigned integer
 * @n: The number to be printed
 * Return: The number of characters printed
 */
int _print_unsigned(unsigned int n)
{
	return _print_number(n);
}

/**
 * _print_octal - Prints an unsigned integer in octal format
 * @n: The number to be printed
 * Return: The number of characters printed
 */
int _print_octal(unsigned int n)
{
	int count = 0;
	unsigned int octal_num[100];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (n != 0)
		{
			octal_num[i] = n % 8;
			n = n / 8;
			i++;

			for (i = i - 1; i >= 0; i--)
			{
				_putchar('0' + octal_num[i]);
				count++;
			}
		}

		return (count);

	}
}

/**
 * _print_hex - Prints an unsigned integer in hexadecimal format
 * @n: The number to be printed
 * @uppercase: If 1, print in uppercase format; otherwise, print in lowercase format
 * Return: The number of characters printed
 */
int _print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char hex_chars[] = "0123456789abcdef";
	if (uppercase)
		hex_chars = "0123456789ABCDEF";

	int hex_num[100];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		while (n != 0)
		{
			hex_num[i] = n % 16;
			n = n / 16;
			i++;
		}
		for (i = i - 1; i >= 0; i--)
		{
			_putchar(hex_chars[hex_num[i]]);
			count++;
		}
	}

	return (count);
}

/**
 * _print_S - Prints a string with non-printable characters
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int _print_S(char *str)
{
	int count = 0;
	char *ptr;

	for (ptr = str; *ptr; ptr++)
	{
		if (*ptr < 32 || *ptr >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (*ptr < 16)
				_putchar('0');
			count += 3 + _print_hex(*ptr, 1);
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}

	return (count);
}

/**
 * _print_pointer - Prints a memory address
 * @ptr: The pointer to be printed
 * Return: The number of characters printed
 */
int _print_pointer(void *ptr)
{
	unsigned long int address = (unsigned long int)ptr;
	int count = 0;

	_putchar('0');
	_putchar('x');
	count += 2;

	count += _print_hex(address, 0);

	return (count);
}

/**
 * _rot13 - Encodes a string using rot13
 * @str: The string to be encoded
 * Return: The encoded string
 */
char *_rot13(char *str)
{
	char *s = str;
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (; *s; s++)
	{
		char *tmp = rot13;
		char *a = alpha;

		while (*a)
		{
		if (*s == *a)
		{
			*s = *tmp;
			break;
		}
		a++;
		tmp++;
		}
	}

	return (str);
}

/**
 * _print_rot13 - Prints a string in rot13 format
 * @str: The string to be printed
 * Return: The number of characters printed
 */
int _print_rot13(char *str)
{
	char *rot13_str = _rot13(str);
	int count = 0;

	while (*rot13_str)
	{
		_putchar(*rot13_str);
		count++;
		rot13_str++;
	}

	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	int printed_chars = 0;
	char buffer[1024];
	int buffer_index = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
	if (*format == '%')
	{
	format++;
	/* Handle format specifiers */
	int length_modifier = 0;
	while (*format == 'l' || *format == 'h')
	{
		if (*format == 'l')
			length_modifier++;
		else if (*format == 'h')
			length_modifier--;
		format++;
	}
		int field_width = 0;
	if (*format == '0')
	{
		format++;
		while (*format >= '0' && *format <= '9')
		{
			field_width = field_width * 10 + (*format - '0');
			format++;
		}
	}
	else if (*format >= '1' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			field_width = field_width * 10 + (*format - '0');
			format++;
		}
	}
		int precision = -1;
	if (*format == '.')
	{
		format++;
		if (*format >= '0' && *format <= '9')
		{
			precision = 0;
			while (*format >= '0' && *format <= '9')
			{
				precision = precision * 10 + (*format - '0');
				format++;
			}
		}
		else if (*format == '*')
		{
			precision = va_arg(args, int);
			format++;
		}
	}
		int zero_flag = 0;
	if (*format == '0')
	{
		zero_flag = 1;
		format++;
	}
		switch (*format)
	{
	case 'c':
		buffer[buffer_index] = va_arg(args, int);
		buffer_index++;
		break;
	case 's':
		/* TODO: Handle strings */
		break;
	case 'd':
	case 'i':
		if (length_modifier >= 1)
		{
					long int num = va_arg(args, long int);
			printed_chars += _print_number(num);
		}
		else
		{
			int num = va_arg(args, int);
			printed_chars += _print_number(num);
		}
		break;
	case 'b':
		if (length_modifier >= 1)
		{
			long unsigned int num = va_arg(args, long unsigned int);
			printed_chars += _print_binary(num);
		}
		else
		{
			unsigned int num = va_arg(args, unsigned int);
			printed_chars += _print_binary(num);
		}
		break;
	case 'u':
		if (length_modifier >= 1)
		{
			unsigned long int num = va_arg(args, unsigned long int);
			printed_chars += _print_unsigned(num);
		}
		else
		{
			unsigned int num = va_arg(args, unsigned int);
			printed_chars += _print_unsigned(num);
		}
		break;
	case 'o':
		if (length_modifier >= 1)
		{
			unsigned long int num = va_arg(args, unsigned long int);
			printed_chars += _print_octal(num);
		}
		else
		{
			unsigned int num = va_arg(args, unsigned int);
			printed_chars += _print_octal(num);
		}
		break;
	case 'x':
		if (length_modifier >= 1)
		{
			unsigned long int num = va_arg(args, unsigned long int);
			printed_chars += _print_hex(num, 0);
		}
		else
		{
			unsigned int num = va_arg(args, unsigned int);
			printed_chars += _print_hex(num, 0);
		}
		break;
	case 'X':
		if (length_modifier >= 1)
		{
			unsigned long int num = va_arg(args, unsigned long int);
			printed_chars += _print_hex(num, 1);
		}
		else
		{
			unsigned int num = va_arg(args, unsigned int);
			                    printed_chars += _print_hex(num, 1);
		}
		break;
	case 'S':
		printed_chars += _print_S(va_arg(args, char *));
		break;
	case 'p':
		printed_chars += _print_pointer(va_arg(args, void *));
		break;
	case 'r':
		printed_chars += _print_reversed(va_arg(args, char *));
		break;
	case 'R':
		printed_chars += _print_rot13(va_arg(args, char *));
		break;
		/* TODO: Handle other format specifiers */
	default:
		buffer[buffer_index] = '%';
		buffer_index++;
		buffer[buffer_index] = *format;
		buffer_index++;
		printed_chars += 2;
		break;
	}
	}
	else
	{
		buffer[buffer_index] = *format;
		buffer_index++;
		printed_chars++;
	}
	/* Flush the buffer if it is almost full or if field width is reached */
	if (buffer_index >= 1023 || (field_width > 0 && buffer_index >= field_width))
	{
	write(1, buffer, buffer_index);
	printed_chars += buffer_index;
	buffer_index = 0;
	}
	format++;
	}
	/* Flush the remaining buffer */
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		printed_chars += buffer_index;
	}
	va_end(args);
	return (printed_chars);
}
