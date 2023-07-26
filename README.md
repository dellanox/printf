# Printf.
```` c
int printf ( const char * format, ... );
````
This is the first group/pair programming taskn on our intense Software
enginneriat ALXerton School, which consists of replicating the **[printf (3)](http://man7.org/linux/man-pages/man3/printf.3.html)** function of language c, calling it this way **_printf.**

This function is part of the standard library **<cstdio>** and to use it we must specify the header file **<stdio.h>**.

Writes the C string pointed by format to the standard output **(stdout)**. If format includes format specifiers (subsequences beginning with **%**), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.
### Parameters
 > **format** -> C string that contains the text to be written to stdout.
 
Where the specifier character at the end is the most significant component, since it defines the type and the interpretation of its corresponding argument:
 Specifier | Output | Example
------------ | ------------- |-----------
 c | Character | A
 s | String of characters | Testing 
 % | A % followed by another % character will write a single % to the stream| %
  i and d | Signed decimal integer | 98 
 b | Unsigned binary | 10101
 u | Unsigned decimal integer | 98
 o | Unsigned octal | 5523
 x | Unsigned hexadecimal integer (lowercase) | 36264eb
 X | Unsigned hexadecimal integer (uppercase) | 36264EB
 r | Reversed string | gnirts |
 R | Rot13 string | cevags
##### Return Value.
On **success**, the **total number** of characters written is returned.
If a writing error occurs, the error indicator (ferror) is set and a negative number is returned.
 
## The tasks.
-[x] **I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life.** 
Write a function that produces output according to a format.

- Prototype:``int _printf(const char *format, ...);``
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
- format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
-- ``c``
-- ``s``
--  ``%``

 -[x] **Education is when you read the fine print. Experience is what you get if you don't**
Handle the following conversion specifiers:
-- ``d``
--``i``
### [Man_3_printf.](https://photos.app.goo.gl/pY1W7jWLFGHLPa3S6)
## Functions use in this project.

````c
Authorized functions and macros

    write (man 2 write)
    malloc (man 3 malloc)
    free (man 3 free)
    va_start (man 3 va_start)
    va_end (man 3 va_end)
    va_copy (man 3 va_copy)
    va_arg (man 3 va_arg)

int _putchar(char c); /*writes the character c to stdout */
int _printf(const char *format, ...);/* function that produces output according to a format.*/
int print_char(va_list c);/*writes the character c to stdout */
int print_string(va_list s);/*writes the character c to stdout */
int print_int(va_list i);/*function that prints an integer */
int print_dec(va_list d);/* function that prints an decimal*/
````

## How to use.
### Complilation
Your code will be compiled on Ubuntu 20.04 LTS with the flags: 
$ gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 *.c -o printf

expected executable after compilation./printf

The files will be compiled this way:
- ``gcc -Wall -Werror -Wextra -pedantic *.c``

linux>$  gcc -Wall -Werror -Wextra -Wno-format -pedantic -std=gnu89 *.c -o printf
linux>$  ./printf
	Let's try to printf a simple sentence.
	Let's try to printf a simple sentence.
	Length:[39, 39]
	Length:[39, 39]
	Negative:[-762534]
	Negative:[-762534]
	Unsigned:[2147484671]
	Unsigned:[2147484671]
	Unsigned octal:[20000001777]
	Unsigned octal:[20000001777]
	Unsigned hexadecimal:[800003ff, 800003FF]
	Unsigned hexadecimal:[800003ff, 800003FF]
	Character:[H]
	Character:[H]
	String:[I am a string !]
	String:[I am a string !]
	Address:[0x7ffe637541f0]
	Address:[0x7ffe637541f0]
	Percent:[%]
	Percent:[%]
	Len:[12]
	Len:[12]
	Unknown:[
	]FF300008 ,ff300
	]0f145736eff
	]%
	]21[:neL]
	Unknown:[%r]
 
linux>$
```
## Contributors
- [Ozioma DC Emerem](https://github.com/dellanox)
- [Uchechukwu Uka](https://github.com/Ucheuka)
