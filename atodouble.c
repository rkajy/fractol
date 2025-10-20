/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:39:15 by radandri          #+#    #+#             */
/*   Updated: 2025/10/20 15:58:54 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}

double atodouble(char *s)
{
    long integer_part = 0;
    long fractional_part = 0;
    double pow;
    int sign = 1;

    pow = 1.0;
    while(is_space(*s))
    {
        s++;
    }
    while(*s == '+' || *s == '-')
    {
        if(*s == '-')
            sign *= -1;
        s++;
    }
    while(*s >= '0' && *s <= '9')
    {
        integer_part = (integer_part * 10) + (*s - '0');
        s++;
    }
    if(*s == '.')
    {
        s++;
        while(*s >= '0' && *s <= '9')
        {
            fractional_part = (fractional_part * 10) + (*s - '0');
            pow *= 10;
            s++;
        }
    }
    return (double)(integer_part * sign) + (double)(fractional_part * sign) / pow;
}
