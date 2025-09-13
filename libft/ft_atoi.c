/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:15:50 by radandri          #+#    #+#             */
/*   Updated: 2025/07/15 21:49:04 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || (c == 32));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	isnegative;
	int	res;

	i = 0;
	isnegative = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		isnegative = 1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (isnegative)
		return (res * -1);
	return (res);
}
