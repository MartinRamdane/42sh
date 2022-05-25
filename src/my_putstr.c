/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** my_putstr
*/

void my_putchar (char c);

int my_putstr(char const *str)
{
    long long int run;
    run = 0;
    while (str[run] == '0') {
        run++;
    }
    while (str[run] != '\0') {
        my_putchar(str[run]);
        run++;
    }
}

int my_putstr_echo(char const *str)
{
    long long int run;
    run = 0;
    while (str[run] == '0') {
        run++;
    }
    while (str[run] != '\0') {
        if (str[run] == '\\' && str[run + 1] == 'n') {
            my_putchar('\n');
            run++;
        } else if (str[run] != '\"' && str[run] != '\'')
            my_putchar(str[run]);
        run++;
    }
}
