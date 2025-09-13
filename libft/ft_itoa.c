/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:22:23 by radandri          #+#    #+#             */
/*   Updated: 2025/07/19 20:47:24 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		n_len;
	char	*res;
	int		isneg;
	int		temp;
	long	nbr;

	nbr = n;
	n_len = ft_int_len(nbr);
	isneg = n < 0;
	if (isneg)
		nbr = -nbr;
	res = malloc((n_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[n_len] = '\0';
	while (n_len != 0)
	{
		temp = (n_len--) - 1;
		res[temp] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (isneg)
		res[n_len] = '-';
	return (res);
}
