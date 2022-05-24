/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** add_tolist
*/

#include "my.h"

void append(t_list **list, char **arg, char *command)
{
    t_list *temp = malloc(sizeof(t_list));
    temp->next = NULL;
    temp->arg = arg;
    temp->command = command;
    if (*list == NULL) {
        *list = temp;
        return;
    }
    t_list *last = *list;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

void print_list(t_list **list)
{
    t_list *temp = *list;
    while (temp) {
        print_arg(temp->arg);
        temp = temp->next;
    }
}
