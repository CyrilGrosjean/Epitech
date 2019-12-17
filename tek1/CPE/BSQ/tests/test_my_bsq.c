/*
** EPITECH PROJECT, 2019
** test my bsq
** File description:
** test file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/bsq.h"
#include <sys/stat.h>

Test(my_bsq, should_display_read_error)
{
    int i = my_bsq("cou");
    cr_assert_eq(i, 84);
}

Test(my_bsq, should_display_square_empty_file)
{
    char file[] = "mouli_maps_solved/intermediate_map_34_137_empty";
    int fd = open(file, O_RDONLY);
    char *str;
    struct stat st;
    int size = 0;

    stat(file, &st);
    size = st.st_size;
    str = malloc(sizeof(char) * (size + 1));
    read(fd, str, size);
    str[size] = '\0';
    cr_redirect_stdout();
    my_bsq("mouli_maps/intermediate_map_34_137_empty");
    cr_assert_stdout_eq_str(str);
    free(str);
}

Test(my_bsq, should_display_square)
{
    char file[] = "mouli_maps_solved/intermediate_map_34_137_with_obstacles_25pc";
    int fd = open(file, O_RDONLY);
    char *str;
    struct stat st;
    int size = 0;

    stat(file, &st);
    size = st.st_size;
    str = malloc(sizeof(char) * (size + 1));
    read(fd, str, size);
    str[size] = '\0';
    cr_redirect_stdout();
    my_bsq("mouli_maps/intermediate_map_34_137_with_obstacles_25pc");
    cr_assert_stdout_eq_str(str);
    free(str);
}

Test(my_bsq, should_display_error_square)
{
    int i = my_bsq("mouli_maps/map_not_good");
    int a = my_bsq("mouli_maps");
    int c = my_bsq("mouli_maps/map_negative");

    cr_assert_eq(i, 84);
    cr_assert_eq(a, 84);
    cr_assert_eq(c, 84);
}