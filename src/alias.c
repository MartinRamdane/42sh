/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-42sh-martin.ramdane
** File description:
** alias
*/

#include "my.h"

void add_to_aliaslist(t_infos *infos, char *line, char *alias)
{
    t_alias **list = &infos->alias;
    t_alias *temp = malloc(sizeof(t_alias));
    temp->next = NULL;
    temp->alias = alias;
    temp->command = line;
    if (*list == NULL) {
        *list = temp;
        return;
    }
    t_alias *last = *list;
    while (last->next != NULL)
        last = last->next;
    last->next = temp;
}

void alias(t_infos *infos, char **arg)
{
    if (my_arr_len(arg) == 0)
        print_all_alias(infos);
    if (my_arr_len(arg) == 1)
        search_alias(infos, arg[1]);
    if (my_arr_len(arg) > 1)
        split_command(infos, arg);
}

void search_alias(t_infos *infos, char *alias)
{
    t_alias *temp = infos->alias;
    while (temp) {
        if (my_strncmp(alias, temp->alias, my_strlen(alias)) == 0) {
            printf("%s ", temp->alias);
            printf("%s\n", temp->command);
            return;
        }
        temp = temp->next;
    }
}

void split_command(t_infos *infos, char **arg)
{
    int len = my_arr_len(arg);
    char *str = malloc(sizeof(char) * 1000);
    my_memset(str, 0, 1000);
    int i = 2;
    char space = ' ';
    while (i <= len) {
        strcat(str, arg[i]);
        if (i + 1 <= len)
            strcat(str, " ");
        i++;
    }
    add_to_aliaslist(infos, str, arg[1]);
}

void print_all_alias(t_infos *infos)
{
    t_alias *temp = infos->alias;
    while (temp) {
        printf("%s ", temp->alias);
        printf("%s\n", temp->command);
        temp = temp->next;
    }
}
