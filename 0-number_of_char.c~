#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char c;
	char *s;
	char percent = '%';

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = (char)va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					write(1, s, 1);
					s++;
					printed_chars++;
				}
				break;
			case '%':
				write(1, &percent, 1);
				printed_chars++;
				break;
			default:
				write(1, format - 1, 1);
				write(1, format, 1);
				printed_chars += 2;
				break;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}

	va_end(args);

	return (printed_chars);
}
