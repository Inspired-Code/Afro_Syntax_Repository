/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmodise <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 23:25:32 by mmodise           #+#    #+#             */
/*   Updated: 2016/04/28 23:43:59 by mmodise          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"

int	ft_strlen(char *str)
{
    int	i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

int     ft_pow(int pow, int in_v)
{
    int     prod_v;
    
    prod_v = 1;
    while(pow > 0)
    {
        prod_v *= in_v;
        pow--;
    }
    return(prod_v);
}


int     ft_atoi(char *str)
{
    int     cnt_v1;
    int     cnt_v2;
    int     *cnv_v;
    int     st_len;
    int     num_v;
    int     sum_v;
    int     sum_v2;
    
    cnt_v1 = 0;
    st_len = ft_strlen(str);
    cnv_v = malloc(st_len + 1);
    sum_v = 0;
    num_v = 0;
    sum_v2 = 0;
    while(str[cnt_v1])
    {
        cnv_v[cnt_v1] = str[cnt_v1] - '0';
        cnt_v1++;
    }
    cnt_v2 = cnt_v1;
    cnt_v1 = 0;
    while(cnt_v1 <= cnt_v2 + 1)
    {
        sum_v = ft_pow(cnt_v2, 10) / 10;
        num_v = sum_v * cnv_v[cnt_v1];
        sum_v2 += num_v;
        cnt_v1++;
        cnt_v2--;
    }
    return(sum_v2);
}
