/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls functions prototypes
*/

#ifndef LS_H_
#define LS_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct file_s {

    char *path;
    char *access_rights;
    int hardlinks;
    char *owner;
    char *owner_group;
    int size;
    char *date;
    char *file_name;
    int blocks;
    long int blksize;

} file_t;

typedef struct flags_s {

    char flag;
    int applied;

} flags_t;

int my_ls(int ac, char **av);
int my_strlen(char *text);
void my_putstr(char *str);
char *my_str_copy(char *src);
void my_sort_array(char **tab);
char *make_path(char *src, char *name);
void fill_struct(file_t *file, char *path, char *name);
void free_files(file_t *files, int count);
char *get_access_right(struct stat st);
char *get_time(struct stat st);
void display_name(file_t *file);
void free_path(char **path);
file_t *get_dir(char *path, int count);
int count_files(char *path);
file_t *apply_flags(flags_t *flag, char **path, file_t *files);
void display_l(file_t *file);
int my_put_nbr(int nb);
void my_putchar(char c);
void flag_l(file_t *files, int count);
char *get_path(char *pathfile);
char *get_name(char *pathfile);
void sort_time_array_struct(file_t *files, int count);
void reverse_array_struct(file_t *files, int count);
void display_d(char *path);
int get_check_flag(flags_t *flag, int index);

#endif
