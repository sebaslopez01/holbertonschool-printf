# Holberton School -printf
## Description
This ```_printf``` is the development of a function that produces an output according to a format provided by .B Holberton School\fB, applying the fundamentals acquired in C language, in order to perform something similar to the C printf function
## Prototype
 ```int _printf(const char *format, ...);```
## Instalation
All your files will be compiled on Ubuntu 20.04 LTS using ```gcc```
### using
The options ```-Wall -Werror -Wextra -pedantic -std=gnu89```

## Compilation 
The code was compiled like this  ```gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c```
## File Descripotions
* **main.h** contains ```math.h```, ```stdlib.h```, ```string.h```, ```stdarg.h```, ```unistd.h``` libraries with their respective prototypes used in the function ```_printf```
* **_printf** is a function that produces output according to a format using the prototype: ```int _printf(const char *format, ...);``` returning the number of characters printed but excluding the null byte used to end the output to strings, The format string consists of zero or more directives
* **get_op_func.c** is a function to compare if a character is in the structure ```format_t```
* **helper_f.c** Contains the arguments to be copied in the buffer, in the functions of type string, character and numbers with the names ```op_string```, ```op_char``` and ```op_number```
* **_printf_test.c** is a function to count the space needed by the new string and this contains the functions ```count_space```, ```fill_string``` and ```_printf2``` 
* **itoa.c** This function handles conversion specifiers: ```d``` and ```i```

## Requirements
### General
* All your files will be compiled on Ubuntu 20.04 LTS using ```gcc```
using the options ```-Wall -Werror -Wextra -pedantic -std=gnu89```
* Code must use ```Betty``` style
* It is not allowed to use global variables.
* No more than 5 features per file
* Prototypes of all functions must be included in their header file called main.h
* send header file
### Authorized functions and macros
* ```write``` (```man 2 write```)
* ```malloc``` (```man 3 malloc```)
* ```free``` (```man 3 free```)
* ```va_start``` (```man 3 va_start```)
* ```va_end``` (```man 3 va_end```)
* ```va_copy``` (```man 3 va_copy```)
* ```va_arg``` (```man 3 va_arg```)

## Examples
#### Integer
 * Intput: ```_printf("Unsigned octal:[%o]\n", ui);```
 * Output: ```Unsigned octal:[20000001777]```
#### Decimal
 * Intput: ```_printf("Negative:[%d]\n", -762534);```
 * Output: ```Negative:[-762534]```
#### Character
 * Intput: ```_printf("Character:[%c]\n", 'H');```
 * Output: ```Character:[H]```
#### String
 * Intput: ```_printf("String:[%s]\n", "I am a string !");```
 * Output: ```String:[I am a string !]```
## Testings


## Task
### Mandatory
0. Write a function that produces output according to a format ```c```, ```s``` and ```%```
1. Handle the following conversion specifiers with ```i``` and ```d```
2. Create a man page for your function called ```man_3_printf```
### Advanced
3. Handle conversion specifier ```b```: unsigned int argument is converted to binary.
4. Handle conversion specifiers ```u```, ```o```, ```x```, ```X```.
5. Use a local buffer of 1024 chars in order to call ```write``` as little as possible.
6. Handle conversion specifier ```p```.
7. Handle conversion specifier ```S```: prints the string.

8. Handle the following markup characters for non-custom conversion specifiers: ```+```, space, and ```#```.
9. Handle the following length modifiers for non-custom conversion specifiers: ```l``` and ```h```, Conversion specifiers to handle: ```d```, ```i```, ```u```, ```o```, ```x```, ```X```.
10. Handle the field width for non-custom conversion specifiers.
11. Handle the precision for non-custom conversion specifiers.
12. Handle the ```0``` flag character for non-custom conversion specifiers.
13. Handle the ```-``` flag character for non-custom conversion specifiers.
14. Handle the custom conversion specifier ```r``` that prints the reversed string.
15. Handle the custom conversion specifier ```R``` that prints the rot13'ed string.
16. All above options should work well together.

## Authors:
* Sebastián López - sebaslopez01
* Alexander Ayala - Alexander-Ayala
