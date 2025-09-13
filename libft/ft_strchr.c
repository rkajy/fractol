/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:03:03 by radandri          #+#    #+#             */
/*   Updated: 2025/07/17 21:08:02 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	pc;
	int		i;

	i = 0;
	pc = (char)c;
	while (s[i])
	{
		if (s[i] == pc)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == pc)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
