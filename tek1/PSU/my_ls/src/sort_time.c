/*
** EPITECH PROJECT, 2020
** sort array of structure
** File description:
** functions to sort
*/

#include "../include/ls.h"

static const char *months[12] = {
    "Jan",
    "Feb",
    "Mar",
    "Avr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
};

int check_month(file_t *file)
{
    int good = 1;
    int month = 0;

    for (month = 0; month < 12; month += 1) {
        good = 1;
        for (int i = 0; file->date[i]; i += 1)
            if (file->date[i] != months[month][i]) {
                good = 0;
                break;
            }
        if (good)
            return (month);
    }
    return (month);
}

int check_date(file_t *file1, file_t *file2)
{
    int month_file1 = check_month(file1);
    int month_file2 = check_month(file2);

    if (month_file1 < month_file2)
        return (1);
    else if (month_file1 > month_file2)
        return (0);
    for (int i = 3; file1->date[i]; i += 1) {
        if (file1->date[i] < file2->date[i])
            return (1);
        else if (file1->date[i] > file2->date[i])
            return (0);
    }
    return (0);

}

int check_sorted_time(file_t *files, int count)
{
    int change = 0;

    for (int i = 1; i < count; i += 1) {
        change = check_date(&files[i - 1], &files[i]);
        if (change)
            return (0);
    }
    return (1);
}

void sort_time_array_struct(file_t *files, int count)
{
    file_t temp;
    int change = 0;

    while (1) {
        for (int i = 1; i < count; i += 1) {
            change = check_date(&files[i - 1], &files[i]);
            if (change) {
                temp = files[i];
                files[i] = files[i - 1];
                files[i - 1] = temp;
            }
        }
        if (check_sorted_time(files, count))
            break;
    }
}

void reverse_array_struct(file_t *files, int count)
{
    int index_reverse = count - 1;
    file_t temp;

    for (int i = 0; i < index_reverse; i += 1) {
        temp = files[i];
        files[i] = files[index_reverse];
        files[index_reverse] = temp;
        index_reverse -= 1;
    }
}