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

int main(int argc, char const *argv[])
{
    main_data_t *data = malloc(sizeof(main_data_t));
    int output;

    ERR_D(MALLOC_ERR, "In: sample", EPITECH_ERR, (!data));
    INFO_FLAG(argc, argv);
    INFO(argc, argv);
    output = sample(data);
    if (output != KO)
        return clean_data(data);
    clean_data(data);
    return KO;
}
