/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int ret = 0;
    int count = 0;
    int neg = 0;

    for (; str[count] < '0' ||  str[count] > '9'; count++) {
        if (str[count] == '-')
            neg++;
        else
            return (-1);
    }
    for (; str[count] != '\0'; count++) {
        if (str[count] < '0' ||  str[count] > '9')
            break;
        ret = ret * 10 + (str[count] - 48);
    }
    if (neg > 0)
        ret = -ret;
    return (ret);
}