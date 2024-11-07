/*
** EPITECH PROJECT, 2024
** my_is_prime.c
** File description:
** Find if the given number is prime
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    for (int i = 1; i < nb; i++) {
        if (nb % i == 0 && i != 1)
            return 0;
    }
    return 1;
}
