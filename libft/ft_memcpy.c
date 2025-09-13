/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:09:39 by radandri          #+#    #+#             */
/*   Updated: 2025/07/13 13:43:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	size_t			i;

	temp_dest = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	i = 0;
	if (!temp_dest && !temp_src)
	{
		return (NULL);
	}
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dst);
}
