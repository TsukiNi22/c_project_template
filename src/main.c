/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main of the project
*/

#include "sample.h"
#include "macro.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    main_data_t *data = NULL;
    bool out = false;

    if (!argv)
        return err_prog(PTR_ERR, "In: main", EPITECH_ERR);
    data = malloc(sizeof(main_data_t));
    if (!data)
        return err_prog(MALLOC_ERR, "In: main", EPITECH_ERR);
    if (print_info_flag(argc, argv, &out) == KO)
        return err_custom("Info -h / -fh", EPITECH_ERR);
    if (print_info(argc, argv, &out) == KO)
        return err_custom("Info -H", EPITECH_ERR);
    if (out)
        return free_data(data);
    if (sample(argc, argv, data) == KO) {
        free_data(data);
        return err_custom("Execution have failed", EPITECH_ERR);
    }
    return free_data(data);
}
