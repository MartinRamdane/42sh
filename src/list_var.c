/*
** EPITECH PROJECT, 2022
** list_var.c
** File description:
** list_var.c
*/

#include "../include/my.h"
#include "../include/script.h"

void add_variable(l_var **list, l_var *maillon)
{
    maillon->next = NULL;
    if (*list == NULL) {
        *list = maillon;
        return;
    }
    l_var *last = *list;
    while (last->next) {
        last = last->next;
    }
    last->next = maillon;
}

void change_end_str(char *str)
{
    int i = 0;
    while (str[i] != '\n') {
        i++;
    }
    str[i] = '\0';
}

int recup_var(char *str, l_var *list_var)
{
    if (check_if_variable(str) == 1) {
        change_end_str(str);
        char *name = take_name_var(str);
        char *value = take_value_var(str);
        l_var *maillon = malloc(sizeof(l_var));
        maillon->name = malloc(sizeof(char) * strlen(name));
        maillon->value = malloc(sizeof(char) * strlen(value));
        maillon->name = strcpy(maillon->name, name);
        maillon->value = strcpy(maillon->value, value);
        add_variable(&list_var, maillon);
        exit(0);
    }
    return 0;
}
