/*
** EPITECH PROJECT, 2024
** sample.h
** File description:
** Sample header
*/

#ifndef SAMPLE
    #define SAMPLE

//----------------------------------------------------------------//
/* TYPEDEF */

/* data */
typedef struct main_data_s {
    void *var;
} main_data_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* sample */
int sample(int argc, char const *argv[], main_data_t *data); // Error: KO

/* init_data */
int init_data(main_data_t *data); // Error: KO
int init_struct_main(main_data_t *data); // Error: KO

/* exit */
int free_data(main_data_t *data); // Error: EPITECH_ERR

#endif /* SAMPLE */
