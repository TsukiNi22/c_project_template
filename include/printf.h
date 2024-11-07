/*
** EPITECH PROJECT, 2024
** printf.h
** File description:
** Headeer for the my_pritnf function
*/

#ifndef PRINTF
    #define PRINTF

    //----------------------------------------------------------------//
    /* INCLUDE */

    /* global */
    #include <stdarg.h> // va_list

    //----------------------------------------------------------------//
    /* DEFINE */

    /* flag */
    #define IDENTIFIER '%'
    #define FLAGS "#0- +*"
    #define FIELD_WIDHT "0123456789*"
    #define PRECISION ".0123456789*"
    #define MODIFIER "lll" //"hlhhllqLjzZt"
    #define SPECIFIERS "diouxXeEfFgGcsp%"

//----------------------------------------------------------------//
/* TYPEDEF */

/* my_printf */
typedef struct printf_data_struc {
    char *str;
    va_list ap;
    char *info;
    char *flag;
    char *field;
    char *precision;
    char *lenght_modifier;
    char *specifiers;
} printf_data_t;

//----------------------------------------------------------------//
/* PROTOTYPE */

/* my_printf */
int my_printf(char *str, ...); // Error: KO
int identifier_encouter(printf_data_t *data, int *i); // Error: KO
int printf_dispatch(printf_data_t *data); // Error: KO

/* get_info */ // Error: NULL
char *get_info_single_char(char *str, char *valid_char_list, int *i, int stop);
char *get_info_mult_char(char *str, char *valid_char_list, int *i, int stop);
int get_precision(va_list ap, char *precision, int basic_return);
int get_field(va_list ap, char *flag, char *field, int basic_return);
int flag_in(char *flag, char flag_to_verif);

/* specifiers */
int specifier_d(printf_data_t *data); // Error: KO
int specifier_i(printf_data_t *data); // Error: KO
int specifier_o(printf_data_t *data); // Error: KO
int specifier_u(printf_data_t *data); // Error: KO
int specifier_x(printf_data_t *data); // Error: KO
int specifier_maj_x(printf_data_t *data); // Error: KO
int specifier_e(printf_data_t *data); // Error: KO
int specifier_maj_e(printf_data_t *data); // Error: KO
int specifier_f(printf_data_t *data); // Error: KO
int specifier_maj_f(printf_data_t *data); // Error: KO
int specifier_g(printf_data_t *data); // Error: KO
int specifier_maj_g(printf_data_t *data); // Error: KO
int specifier_c(printf_data_t *data); // Error: KO
int specifier_s(printf_data_t *data); // Error: KO
int specifier_p(printf_data_t *data); // Error: KO
int specifier_percent(printf_data_t *data); // Error: KO

int specifier_null(printf_data_t *data);

/* sous_specifier */ // Error: KO
int specifier_g_f(printf_data_t *data, int precision, long double nbr);
int specifier_g_e(printf_data_t *data, int precision, long double nbr);
int specifier_maj_g_f(printf_data_t *data, int precision, long double nbr);
int specifier_maj_g_e(printf_data_t *data, int precision, long double nbr);

#endif /* PRINTF */
