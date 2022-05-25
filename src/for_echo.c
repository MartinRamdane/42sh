/*
** EPITECH PROJECT, 2022
** for_echo.c
** File description:
** for_echo.c
*/

#include "../include/my.h"
#include "../include/script.h"

void echo_char_simple2(char c)
{
    if (c == '\e') {
        my_putchar('\e'); return;
    }
    if (c == '\f') {
        my_putchar('\f'); return;
    }
    if (c == '\r') {
        my_putchar('\r'); return;
    }
    if (c == '\t') {
        my_putchar('\t'); return;
    }
    if (c == '\v') {
        my_putchar('\v'); return;
    }
    my_putchar(c);
}

void echo_char_simple(char c)
{
    if (c == '\n') {
        my_putchar('\n'); return;
    }
    if (c == '\a') {
        my_putchar('\a'); return;
    }
    if (c == '\b') {
        my_putchar('\b'); return;
    }
    print_char_simple2(c);
}

void print_char_simple2(char c)
{
    if (c == '\e') {
        my_putstr_echo("\\e"); return;
    }
    if (c == '\f') {
        my_putstr_echo("\\f"); return;
    }
    if (c == '\r') {
        my_putstr_echo("\\r"); return;
    }
    if (c == '\t') {
        my_putstr_echo("\\t"); return;
    }
    if (c == '\v') {
        my_putstr_echo("\\v"); return;
    }
    if (c != '\'' && c != '\"')
        my_putchar(c);
}

void print_char_simple(char c)
{
    if (c == '\n') {
        my_putstr_echo("\\n"); return;
    }
    if (c == '\a') {
        my_putstr_echo("\\a"); return;
    }
    if (c == '\b') {
        my_putstr_echo("\\b"); return;
    }
    print_char_simple2(c);
}
