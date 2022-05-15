/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** get_env
*/

#include "my.h"

char *move_pointer(char *pointer)
{
    int i = 0, j = 0;
    char *val = malloc(sizeof(char) * 1000);
    while (pointer[i] != 61) {
        i++;
    }
    i++;
    while (pointer[i] != '\0') {
        val[j] = pointer[i];
        j++;
        i++;
    }
    val[j] = '\0';
    return val;
}

char *get_env(char **env, char *find)
{
    char **tmp = env;
    for (int i = 0; tmp[i] != NULL; i++){
        if (my_strncmp(tmp[i], find, my_strlen(find)) == 0) {
            return (move_pointer(tmp[i]));
        }
    }
    return NULL;
}

int env_checker(char **env, char *find)
{
    char **tmp = my_arrcpy(env);
    char **parsed = get_var_env(tmp, "=");
    for (int i = 0; parsed[i] != NULL; i++){
        if (my_strncmp(parsed[i], find, my_strlen(parsed[i])) == 0) {
            return (0);
        }
    }
    write(2, find, my_strlen(find));
    write(2, ": Undefined variable.\n", 23);
    return (-2);
}

char *get_path(char **env, char *find, char *path)
{
    char **tmp = env;
    for (int i = 0; tmp[i] != NULL; i++){
        if (my_strncmp(tmp[i], find, my_strlen(find)) == 0) {
            return (move_pointer(tmp[i]));
        }
    }
    return NULL;
}
