/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** Transform a str in a world array
*/

#include "char.h"
#include "include.h"
#include "define.h"
#include "error.h"

static int is_pr(char c)
{
    int c1 = (c >= 'a' && c <= 'z');
    int c2 = (c >= 'A' && c <= 'Z');
    int c3 = (c >= '0' && c <= '9');

    if (!(c1 + c2 + c3))
        return 0;
    return 1;
}

static int get_word_nbr(char const *str)
{
    int n = 0;
    int new = 1;

    if (!str)
        return err_dispatch(PTR_ERR, "In: str_to_word_array 1.1", -1);
    for (int i = 0; str[i]; i++) {
        if (is_pr(str[i]) && new) {
            new = 0;
            n++;
        } else
            new = 1;
    }
    return n;
}

static void raaaa(int *n, int *i_word)
{
    if (!n || !i_word)
        return err_dispatch_v(PTR_ERR, "In: to_word_array 3.1");
    *n += 1;
    *i_word = 0;
}

static void raaaa_2(char *word, char const *str, int *i_word, int i)
{
    if (!word || !str || !i_word)
        return err_dispatch_v(PTR_ERR, "In: to_word_array 2.1");
    word[*i_word] = str[i];
    *i_word++;
}

char **my_str_to_word_array(char const *str)
{
    int word_nbr = get_word_nbr(str);
    char **word_array = malloc(sizeof(char *) * (word_nbr + 1));
    char *word = malloc(sizeof(char) * my_strlen(str));
    int n = 0;
    int i_word = 0;

    if (!word_array || !word || !str)
        err_dispatch_n(UNDEF_ERR, "In: to_word_array");
    for (int i = 0; str[i]; i++) {
        if (is_pr(str[i]))
            raaaa_2(word, str, &i_word, i);
        if ((i > 0 && !is_pr(str[i]) && is_pr(str[i - 1])) || !str[i + 1]) {
            word[i_word] = '\0';
            word_array[n] = malloc(sizeof(char) * my_strlen(word));
            my_strcpy(word_array[n], word);
            raaaa(&n, &i_word);
        }
    }
    word_array[word_nbr] = NULL;
    return word_array;
}
