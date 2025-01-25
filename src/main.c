/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** Main of the project
*/

#include "sample.h"
#include "macro.h"
#include "error.h"
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    main_data_t data = {0};
    bool out = false;
    int res = 0;

    if (!argv)
        return err_prog(PTR_ERR, "In: main", EPITECH_ERR);
    if (print_info_flag(argc, argv, &out) == KO)
        return err_custom("Info -h / -fh", EPITECH_ERR);
    if (print_info(argc, argv, &out) == KO)
        return err_custom("Info -H", EPITECH_ERR);
    if (out)
        return free_data(&data);
    res = sample(argc, argv, &data);
    if (res == KO || res == FATAL_ERR) {
        if (res != FATAL_ERR)
            free_data(&data);
        return err_custom("Execution have failed", EPITECH_ERR);
    }
    return free_data(&data);
}
