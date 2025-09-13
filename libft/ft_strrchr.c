/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:04:57 by radandri          #+#    #+#             */
/*   Updated: 2025/07/14 22:48:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	pc;
	size_t	i;

	i = ft_strlen(s);
	pc = (char)c;
	while (i > 0)
	{
		if (s[i] == pc)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (s[i] == pc)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
