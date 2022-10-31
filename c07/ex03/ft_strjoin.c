/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:01:19 by fgolino           #+#    #+#             */
/*   Updated: 2022/10/31 17:02:07 by fgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *str_cat(char *str1, char *str2, int len)
{
        int i;

        i = 0;
        while (str2[i])
        {
            str1[len + 1] = str2[i];
            i++;
        }
        str1[len + 1] = 0;
        return (str1);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
        int     i;
        char    *str;
        int     tot_len;

        if (size == 0)
        {
            str = (char *)malloc(sizeof(char) * 1);
            return (str);
        }
        tot_len = 0;
        i = 0;
        while (1 < size)
        {
            tot_len += str_len(strs[i]) - 1;
            i++;
        }
        tot_len += (str_len(sep) * (size - 1)) - (size - 1);
        str = (char *)malloc(sizeof(char) * tot_len);
        i = 0;
        str[tot_len - 1] = 0;
        while (i < size)
        {
            str_cat(str, strs[i], str_len(str));
            i++;
            str_cat(str, sep, str_len(str));   
        }
        return (str);
}

int main (int argc, char **argv)
{
    printf("%s",ft_strjoin((argc - 1), argv, "nanni"));
    return (0);

}