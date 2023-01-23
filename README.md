0. Write a function that produces output according to a format.
	1. Prototype: int _printf(const char *format, ...);
	2. Returns: the number of characters printed (excluding the null byte used to end output to strings)
	3. write output to stdout, the standard output stream
	4. format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers: c, s, %
2. Handle the following conversion specifiers:
	1. d
	2. i
3. Handle the following custom conversion specifiers:
	1. b: the unsigned int argument is converted to binary
4. Handle the following conversion specifiers:
	1. u
	2. o
	3. x
	4. X
5. Use a local buffer of 1024 chars in order to call write as little as possible.
6. Handle the following custom conversion specifier:
	1. S : prints the string.
	2. Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
7. Handle the following conversion specifier: p.
8. Handle the following flag characters for non-custom conversion specifiers:
	1.\+
	2. space
	3. \#
9. Handle the following length modifiers for non-custom conversion specifiers:
	1. l
	2. h
	3. Conversion specifiers to handle: d, i, u, o, x, X
10. Handle the field width for non-custom conversion specifiers.
11. Handle the precision for non-custom conversion specifiers.
12. Handle the 0 flag character for non-custom conversion specifiers.
13. Handle the - flag character for non-custom conversion specifiers.
14. Handle the following custom conversion specifier:
	1. r : prints the reversed string
15. Handle the following custom conversion specifier:
	1. R: prints the rot13'ed string
16. All the above options work well together.
