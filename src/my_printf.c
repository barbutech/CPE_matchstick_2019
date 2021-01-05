/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "../include/my.h"

int find_the_flag(char format)
{
    char *ptr = "dis";
    int count = 0;

    while (format != ptr[count] && ptr[count] != '\0')
        count++;
    if (ptr[count] != '\0')
        return (count);
    else
        return (count);
}

int flag_int(va_list listpointer)
{
    my_put_nbr(va_arg(listpointer, int));
    return (0);
}

int flag_string(va_list listpointer)
{
    my_putstr(va_arg(listpointer, char *));
    return (0);
}

int ptr_function(char format, va_list listpointer)
{
    int a = find_the_flag(format);
    int (*function[4])(va_list);
    function[0] = &flag_int;
    function[1] = &flag_int;
    function[2] = &flag_string;

    if (a == 84)
        return (84);
    function[a](listpointer);
    return (0);
}

int my_printf(char *format , ...)
{
    int i = 0;
    va_list listpointer;

    va_start(listpointer, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            ptr_function(format[i + 1], listpointer);
            i++;
        }
        else
            write(1, &format[i], 1);
        i++;
    }
    va_end(listpointer);
}
