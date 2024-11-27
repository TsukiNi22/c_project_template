/*
** EPITECH PROJECT, 2024
** get_file.c
** File description:
** Read and put a file in a str
*/

#include "char.h"
#include "memory.h"
#include "define.h"
#include "error.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int get_file_size(char const *file)
{
    struct stat stats;

    ERR_D(PTR_ERR, "In: get_file > get_file_size", KO, (!file));
    stat(file, &stats);
    return stats.st_size;
}

static int my_calloc_c_local(char *tmp)
{
    ERR_D(PTR_ERR, "In: my_calloc_c_local", KO, (!tmp));
    for (int i = 0; i < 4097; i++)
        tmp[i] = '\0';
    return OK;
}

char *get_file(char const *file)
{
    char *file_c = NULL;
    char tmp[4097] = {0};
    int fd;
    int res;

    ERR_DN(PTR_ERR, "In: get_file", (!file));
    ERR_DN(UNDEF_ERR, "In: get_file 1",
    (my_malloc_c(&file_c, get_file_size(file) + 1) == KO));
    ERR_DN(UNDEF_ERR, "In: get_file 2", (!file_c));
    fd = open(file, O_RDONLY);
    ERR_DN(OP_FILE_ERR, "In: get_file", (fd == -1));
    do {
        res = read(fd, tmp, 4096);
        ERR_DN(READ_FILE_ERR, "In: get_file", (res == -1));
        ERR_DN(UNDEF_ERR, "In: get_file 3", (!my_strcat(file_c, tmp)));
        ERR_DN(UNDEF_ERR, "In: get_file 4",
        (my_calloc_c_local(tmp) == KO));
    } while (res == 4096);
    close(fd);
    return file_c;
}
