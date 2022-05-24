/*
** EPITECH PROJECT, 2022
** B-PSU-101-MAR-1-1-minishell1-adam.elaoumari
** File description:
** my
*/

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#ifndef MY_H_
    #define MY_H_

struct infos {
    int ac;
    char **av;
    char **env;
    char *command;
    char **args;
    int right_type;
    int left_type;
    int pipe;
    int *pipe_int;
    char *right_redir;
    char *left_redir;
    bool redirect;
    int save_stdout;
    int save_stdin;
    int my_pipe[2];
    bool is_otherside;
    int return_val;
    int pipe_nb;
    int pipe_run;
    int fd_in;
    struct list *list;
} typedef t_infos;

struct list {
    char **arg;
    char *command;
    struct list *next;
} typedef t_list;

int cond(char c);
int my_putstr(char const *str);
int main (int argc, char **argv, char **env);
char *my_strstr(char *str, const char *to_find);
char *get_env(char **env, char *find);
char **arg_to_str(char *arg);
int get_nb_arr(char **arg);
void print_arg(char **arg);
char *my_strcpy(char *dest, char const *src);
char *check_path(char **path, char *exec, char **arr);
char **parse_path(char *path, char *delim, char **old);
char *move_pointer(char *pointer);
bool file_exists (char *filename);
void make_exec(t_infos *infos);
void my_memset(char *pointer, int nb, int size);
char **my_arrcpy(char **src);
int make_built(char **arg, char **env, t_infos *infos);
char *my_strcat (char *dest, char const *src);
int exec(t_infos *infos);
int my_setenv(char **env, char **arg);
char *parse_env_var(char **env, char *arg);
char *get_words_nb(char *str);
char *get_words_nb_2(char *str);
char *remove_trailing_spaces(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);
int check_errors(int status, pid_t p);
char *my_strcat (char *dest, char const *src);
int exec_tty(int argc, char **argv, char **env, char *line);
int run_tty(char **env, char *line);
int my_strncmp(char const *s1, char const *s2, int n);
bool folder_exists(char *path);
int change_directory(char **arg, char **env);
int get_words(char *arg);
void manage_exit(int size, int tty_val, int val);
int env_checker(char **env, char *find);
char **get_var_env(char **env, char *delim);
int env_err(char *arg, int pos, char **env);
void parse_env(char **arg, char **env);
int check_env(char **env, char *arg);
void update_pwd(char **env, char *new);
int my_get_nbr(char *str);
int exit_values(char **arg);
int check_exit_utils(char val);
void manage_ctrl_c(int my_signal);
bool file_exists(char *filename);
int check_exit_val(char *val);
char *get_path(char **env, char *find, char *path);
int replace_env(char **env, char *var, char *val);
int make_built_sec(char **arg, char **env, t_infos *infos);
int my_unsetenv(char **env, char **arg);
void print_prompt(char **env);
void hide_ctrl(char **env, int tty_val);
int exec_shell(t_infos *infos);
int check_dir_utils(char **arg, char **env, char **env_cp);
int return_value(int sign);
int my_arr_len(char **arr);
void write_error_message(char *path);
void write_error_cd(char *path);
int check_slash(char *arg);
int check_special_cases(char **env, char **arg);
int my_arrlen(char **arr);
char **malloc_arr(int words);
int skip_words(int i, char *str);
char **parse_arr(char *line);
void get_redirection(t_infos *infos, char *line);
char *get_redirection_val(char *line, int type);
int my_execve(t_infos *infos);
int handling_folder_files(t_infos *infos);
void handle_redirections(t_infos *infos);
int get_filesize(char *filename);
void do_redirect(int fd, char *path, int val, t_infos *infos);
void remove_endspaces(char *str);
void check_withoutpipe(t_infos *infos, char *line);
void run_withoutpipe(t_infos *infos, char *line);
void check_withpipe(t_infos *infos, char *line);
void run_withpipe(t_infos *infos, char *line);
int contains_spaces(char *str);
void get_numberofpipes(t_infos *infos, char *tmp2);
void make_exec2(t_infos *infos);
void handle_pipe(t_infos *infos, int p);
int exec2(t_infos *infos);
void append(t_list **list, char **arg, char *command);
void print_list(t_list **list);
int my_execve_pipe(t_infos *infos, t_list *node, int fd_in, int *p);
void loop_pipe(t_infos *infos);
void free_arr(char **arr);
void get_redirection2(t_infos *infos, char *line);
void my_execpipe(t_infos *infos, int fd_in, int *my_pipe);
int handling_folder_files_pipe(t_list *list, t_infos *infos);
int get_nbofpipes(char *str);
int is_viable(char *tmp2);
void utils_pipe(t_infos *infos, int run, int pipe_nb);
int check_builtin_pipe(t_infos *infos, t_list *node);
int handling_folder_files_pipe2(t_list *list, t_infos *infos);
void get_separators(t_infos *infos, char *line);
void double_ampersand(t_infos *infos, char *line);
void get_double_pipes(t_infos *infos, char *line);
int check_double_pipes(char *line, int i);
#endif/* !MY_H_ */
