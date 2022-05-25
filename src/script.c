/*
** EPITECH PROJECT, 2022
** script.c
** File description:
** script.c
*/

#include "../include/my.h"
#include "../include/script.h"

char *take_value_var(char *str)
{
    int i = 0;
    while (str[i] != '=') {
        i++;
    }
    i = i + 1; int len = 0; int j = i;
    while (str[i] != '\0') {
        len ++; i++;
    }
    char *tmp = malloc(sizeof(char) * len);
    i = 0;
    while (str[j] != '\0') {
        tmp[i] = str[j];
        i++; j++;
    }
    tmp[i] = '\0';
    return (tmp);
}

char *take_name_var(char *str)
{
    int i = 0;
    while (str[i] != '=') {
        i++;
    }
    char *tmp = malloc(sizeof(char) * (i + 1));
    int j = 0; i = 0;
    while (str[j] != '=') {
        tmp[i] = str[j];
        i++; j++;
    }
    tmp[i] = '\0';
    return (tmp);
}

int check_if_variable(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] == '=')
            return 1;
        i++;
    }
    return 0;
}

char *take_name_var2(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str));
    int i = 1; int j = 0;
    while (str[i]) {
        tmp[j] = str[i];
        j++; i++;
    }
    return (tmp);
}

void echo_var(char *str, l_var *list)
{
    char *name_var = take_name_var2(str);
    while (list != NULL) {
        if (strstr(list->name, name_var)) {
            printf("%s\n", list->value);
            return;
        }
        list = list->next;
    }
    printf("\n");
    return;
}
