/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:40:22 by radandri          #+#    #+#             */
/*   Updated: 2025/10/24 23:12:52 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

double	atodouble(const char *s)
{
	long	int_part;
	long	frac_part;
	double	div;
	int		sign;

	int_part = 0;
	frac_part = 0;
	div = 1.0;
	while (ft_is_space(*s))
		s++;
	sign = get_sign(&s);
	while (*s >= '0' && *s <= '9')
		int_part = int_part * 10 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			frac_part = frac_part * 10 + (*s++ - '0');
			div *= 10.0;
		}
	}
	return (sign * (int_part + ((double)frac_part / div)));
}
