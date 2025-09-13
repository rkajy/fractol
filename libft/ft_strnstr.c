/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:13:02 by radandri          #+#    #+#             */
/*   Updated: 2025/07/15 11:58:06 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (!haystack && len == 0)
	{
		if (!needle)
			return (NULL);
		return (NULL);
	}
	needle_len = ft_strlen(needle);
	i = 0;
	if (needle[i] == 0)
	{
		return ((char *)haystack);
	}
	while (haystack[i] && i + needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
		{
			return ((char *)(&(haystack[i])));
		}
		i++;
	}
	return (NULL);
}
