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
    main_data_t *data = malloc(sizeof(main_data_t));
    bool out = false;
    int res = OK;

    ERR_D(PTR_ERR, "In: main", EPITECH_ERR, (!argv));
    ERR_D(MALLOC_ERR, "In: main", EPITECH_ERR, (!data));
    INFO_FLAG(argc, argv, &out);
    ERR_C("Info -h / -fh", EPITECH_ERR, (res == KO));
    EXIT(out, OK);
    INFO(argc, argv, &out);
    ERR_C("Info -H", EPITECH_ERR, (res == KO));
    EXIT(out, OK);
    if (sample(argc, argv, data) == KO) {
        ERR_C("clean_data have failed after an excution failed", KO,
        (clean_data(data) == EPITECH_ERR));
        return err_custom("Execution have failed", KO);
    }
    return clean_data(data);
}
