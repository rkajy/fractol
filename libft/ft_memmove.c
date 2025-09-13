/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:12:13 by radandri          #+#    #+#             */
/*   Updated: 2025/07/14 18:25:05 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *)dst;
	csrc = (char *)src;
	if (!dst && !src)
		return (NULL);
	if (cdest > csrc)
	{
		while (len > 0)
		{
			len--;
			cdest[len] = csrc[len];
		}
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dst);
}
