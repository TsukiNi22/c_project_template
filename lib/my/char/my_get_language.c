/*
** EPITECH PROJECT, 2024
** get_language.c
** File description:
** Vous savait je ne pense pas qu il y ait de bonne ou de mauvaise descrition
** pour moi la vie c est avant tous des fonctions...
*/

#include "char.h"
#include "write.h"
#include "language.h"
#include "error.h"

static float my_strlen_local(char const *str)
{
    float count = 0;

    ERR_D(PTR_ERR, "In: my_get_language > my_strlen_local", KO, (!str));
    for (int i = 0; str[i]; i++) {
        if (my_char_isupper(str[i]) || my_char_islower(str[i]))
            count++;
    }
    return count;
}

static int dispatch_bis(int smallest)
{
    if (smallest == 0)
        return my_putstr(1, "English");
    if (smallest == 1)
        return my_putstr(1, "French");
    if (smallest == 2)
        return my_putstr(1, "German");
    if (smallest == 3)
        return my_putstr(1, "Spanish");
    return KO;
}

static int dispatch(float *lg)
{
    int smallest = 0;
    int res[3];

    ERR_D(PTR_ERR, "In: my_get_language > dispatch", KO, (!lg));
    for (int i = 0; i < 4; i++) {
        if (lg[i] > lg[smallest])
            smallest = i;
    }
    res[0] = my_putstr(1, "=> ");
    res[1] = dispatch_bis(smallest);
    res[2] = my_putchar('\n');
    ERR_D(WRITE_ERR, "In: my_get_language > dispatch", KO,
    (((res[0] < 0) + (res[1] < 0) + (res[2] < 0)) > 0));
    return OK;
}

static float get_coef(int lg, char c)
{
    char eng[] = ENGLISH;
    char fr[] = FRENCH;
    char ger[] = GERMAN;
    char sp[] = SPANISH;
    int res = my_get_index(eng, c) * (lg == 0) +
    my_get_index(fr, c) * (lg == 1) +
    my_get_index(ger, c) * (lg == 2) +
    my_get_index(sp, c) * (lg == 3);

    ERR_D(PTR_ERR, "In: my_get_language > var_f", KO, (res < 0));
    return 1 / ((float) res + 1);
}

static int var_f(float *lg_en, float *lg_fr)
{
    float lg_en_clone[] = {8.167, 1.492, 2.782, 4.253, 12.702,
    2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025, 2.406,
    6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758,
    0.978, 2.360, 0.150, 1.974, 0.074};
    float lg_fr_clone[] = {7.636, 0.901, 3.260, 3.669, 14.715,
    1.066, 0.866, 0.737, 7.529, 0.545, 0.049, 5.456, 2.968,
    7.095, 5.796, 2.521, 1.362, 6.693, 7.948, 7.244, 6.311,
    1.838, 0.017, 0.215, 0.308, 0.074};

    ERR_D(PTR_ERR, "In: my_get_language > var_f", KO, (!lg_en || !lg_fr));
    for (int i = 0; i < 26; i++) {
        lg_en[i] = lg_en_clone[i];
        lg_fr[i] = lg_fr_clone[i];
    }
    return OK;
}

static int var_s(float *lg_ger, float *lg_sp)
{
    float lg_ger_clone[] = {6.516, 1.886, 2.732, 5.076, 16.396,
    1.656, 3.009, 4.577, 6.550, 0.268, 1.417, 3.437, 2.534,
    9.776, 2.594, 0.670, 0.018, 7.003, 7.270, 6.154, 4.166,
    0.634, 1.921, 0.034, 0.039, 1.134};
    float lg_sp_clone[] = {11.525, 2.215, 4.019, 5.010, 12.181,
    0.692, 1.768, 0.703, 6.247, 0.493, 0.011, 4.967, 3.157,
    6.712, 8.683, 2.510, 0.877, 6.871, 7.977, 4.632, 3.927,
    1.138, 0.017, 0.215, 1.008, 0.467};

    ERR_D(PTR_ERR, "In: my_get_language > var_s", KO, (!lg_ger || !lg_sp));
    for (int i = 0; i < 26; i++) {
        lg_ger[i] = lg_ger_clone[i];
        lg_sp[i] = lg_sp_clone[i];
    }
    return OK;
}

static int get_lg_bis_coef(float nb, float percent, int j, int i)
{
    return (nb <= percent) * get_coef(j, i + 97);
}

int get_language(char const *str)
{
    float percent;
    float lg_en[26];
    float lg_fr[26];
    float lg_ger[26];
    float lg_sp[26];
    float *lg[] = {lg_en, lg_fr, lg_ger, lg_sp};
    float lg_coef[4] = {0};
    int res;

    ERR_D(PTR_ERR, "In: my_get_language", KO, (!str));
    ERR_D(UNDEF_ERR, "In: my_get_language", KO,
    (var_f(lg_en, lg_fr) == KO || var_s(lg_ger, lg_sp) == KO));
    for (int i = 0; i < 26; i++) {
        percent = count_occurence(str, (char) (i + 97)) / my_strlen_local(str);
        percent = percent * 100 - percent * 0.1;
        for (int j = 0; j < 4; j++)
            lg_coef[j] += get_lg_bis_coef(lg[j][i], percent, j, i);
    }
    return dispatch(lg_coef);
}
