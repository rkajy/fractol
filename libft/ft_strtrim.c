/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:50:37 by radandri          #+#    #+#             */
/*   Updated: 2025/07/19 19:57:58 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_to_strim(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i_first;
	size_t	j_last;
	size_t	k;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i_first = 0;
	while (s1[i_first] && is_to_strim(s1[i_first], set))
		i_first++;
	j_last = ft_strlen(s1) - 1;
	if (j_last + 1 == 0 || j_last + 1 == i_first)
		return (ft_strdup(""));
	while (s1[j_last] && is_to_strim(s1[j_last], set))
		j_last--;
	if (j_last < i_first)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (j_last - i_first + 2));
	if (!res)
		return (NULL);
	k = 0;
	while (i_first <= j_last)
		res[k++] = s1[i_first++];
	res[k] = '\0';
	return (res);
}
