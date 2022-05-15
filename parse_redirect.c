/*
** EPITECH PROJECT, 2022
** B-PSU-210-MAR-2-1-minishell2-adam.elaoumari
** File description:
** parse_redirect
*/

#include "my.h"

void get_redirection(t_infos *infos, char *line)
{
    if (my_strstr(line, ">>")) {
        infos->right_type = 2;
        infos->right_redir = get_redirection_val(line, 2);
        remove_endspaces(infos->right_redir);
    }
    if (my_strstr(line, ">")) {
        infos->right_type = 1;
        infos->right_redir = get_redirection_val(line, 1);
        remove_endspaces(infos->right_redir);
    }
    get_redirection2(infos, line);
}

void get_redirection2(t_infos *infos, char *line)
{
    if (my_strstr(line, "<<")) {
        infos->left_type = 3;
        infos->left_redir = get_redirection_val(line, 3);
        remove_endspaces(infos->left_redir);
    }
    if (my_strstr(line, "<")) {
        infos->left_type = 3;
        infos->left_redir = get_redirection_val(line, 3);
        remove_endspaces(infos->left_redir);
    }
}

char *get_redirection_val(char *line, int type)
{
    int def = 0, j = 0, i = 0;
    char c;
    if (type == 1 || type == 2)
        c = '>';
    if (type == 3 || type == 4)
        c = '<';
    while (line[i] != c)
        i++;
    def = i;
    while (line[i] == c || line[i] == ' ')
        i++;
    char *str = malloc(sizeof(char) * my_strlen(line));
    for (;line[i] != '\0'; i++) {
        str[j] = line[i];
        j++;
    }
    str[j] = '\0';
    for (; line[def] == ' '; def--);
    line[def] = '\0';
    return str;
}
