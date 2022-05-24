/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** str_len.c
*/

int my_strlen(char const *str)
{
    int run;
    run = 0;
    while (str[run] != '\0') {
        run++;
    }
    return (run);
}
