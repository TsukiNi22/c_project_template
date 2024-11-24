/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** Transform a str in a world array
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"
#include <stdlib.h>
#include <stdbool.h>

static bool is_pr(char c)
{
    int c1 = (c >= 'a' && c <= 'z');
    int c2 = (c >= 'A' && c <= 'Z');
    int c3 = (c >= '0' && c <= '9');

    if (!(c1 + c2 + c3))
        return false;
    return true;
}

static int get_word_nbr(char const *str)
{
    bool new = true;
    int n = 0;

    ERR_D(PTR_ERR, "In: my_str_to_word_array > reset_val", KO, (!str));
    for (int i = 0; str[i]; i++) {
        if (is_pr(str[i]) && new) {
            new = false;
            n++;
        } else
            new = true;
    }
    return n;
}

static int reset_val(int *n, int *i_word)
{
    ERR_D(PTR_ERR, "In: my_str_to_word_array > reset_val", KO,
    (!n || !i_word));
    (*n)++;
    *i_word = 0;
    return KO;
}

static int incrementation(char *word, char const *str, int *i_word, int i)
{
    ERR_D(PTR_ERR, "In: my_str_to_word_array > incrementation", KO,
    (!word || !str || !i_word));
    word[*i_word] = str[i];
    (*i_word)++;
    return OK;
}

char **my_str_to_word_array(char const *str)
{
    int word_nbr = get_word_nbr(str);
    char **word_array = malloc(sizeof(char *) * (word_nbr + 1));
    char *word = malloc(sizeof(char) * my_strlen(str));
    int n = 0;
    int i_word = 0;

    ERR_DN(PTR_ERR, "In: my_str_to_word_array", (!str));
    ERR_DN(UNDEF_ERR, "In: my_str_to_word_array", (!word || !word_array));
    for (int i = 0; str[i]; i++) {
        ERR_DN(PTR_ERR, "In: my_str_to_word_array",
        (is_pr(str[i]) && incrementation(word, str, &i_word, i) == KO));
        if ((i > 0 && !is_pr(str[i]) && is_pr(str[i - 1])) || !str[i + 1]) {
            word[i_word] = '\0';
            my_malloc_c(&word_array[n], my_strlen(word));
            ERR_DN(UNDEF_ERR, "In: my_str_to_word_array",
            (!my_strcpy(word_array[n], word)));
            ERR_DN(UNDEF_ERR, "In: s_t_w_arr", (reset_val(&n, &i_word) == KO));
        }
    }
    return word_array;
}
