/*
** EPITECH PROJECT, 2025
** delete_hashtable.c
** File description:
** Delete a given hashtable
*/

#include "define.h"
#include "hashtable.h"
#include "error.h"
#include <stdlib.h>

int free_hash_data(void *data)
{
    hash_linked_data_t *tmp = NULL;

    if (!data)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    tmp = (hash_linked_data_t *) data;
    if (!tmp->key || !tmp->value)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    free(tmp->key);
    free(tmp->value);
    free(tmp);
    return OK;
}

int free_hash_keys(char **keys)
{
    if (!keys)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    for (int i = 0; keys[i]; i++)
        free(keys[i]);
    free(keys);
    return OK;
}

int delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return err_prog(PTR_ERR, KO, ERR_INFO);
    for (int i = 0; i < ht->len; i++) {
        if (ht->linked[i]
            && delete_linked(&free_hash_data, &(ht->linked[i])) == KO)
            return err_prog(UNDEF_ERR, KO, ERR_INFO);
    }
    free(ht->linked);
    free(ht);
    return OK;
}
