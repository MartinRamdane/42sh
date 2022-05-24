/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** my_strtoword_array
*/

#include "my.h"

int is_a_char(char c)
{
    if ((c >= 33 && c <= 126 ))
        return 1;
    return 0;
}

int use_cond(char *str, char *my_word, int i, int j)
{
    if (str[i] != 9 && str[i + 1] != '\0' && str[i + 1] != ' ' &&
    str[i + 1] != '\n' && str[i + 1] != 9 || str[i] != ' ' &&
    str[i] == ' ' && str[i] == '\n' || str[i] != ' ' &&
    str[i] != 9 && str[i] != 10) {
        my_word[j] = str[i];
        return 1;
    }
    return 0;
}

char *remove_trailing_spaces(char *str)
{
    int i = 0;
    i = skip_words(i, str);
    int j = 0;
    char *my_word = malloc(sizeof(char) * 10000);
    while (str[i] != '\0') {
        if (str[i] == 9 && str[i] != ' ' &&
        str[i + 1] != 9 && str[i + 1] != 32 && str[i + 1] != '\0') {
            my_word[j] = 32;
            j++;
        }
        if (use_cond(str, my_word, i, j))
            j++;
        i++;
    }
    my_word[j] = '\0';
    return my_word;
}
