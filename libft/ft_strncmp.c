/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:06:32 by radandri          #+#    #+#             */
/*   Updated: 2025/10/20 16:04:19 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares up to n characters of two strings lexicographically.
 *
 * This function compares the two strings s1 and s2, but not more than n
 * characters. The comparison is done using unsigned characters, so that
 * '\200' is greater than '\0'.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 *
 * @return An integer less than, equal to, or greater than zero if s1 (or the
 *         first n bytes thereof) is found, respectively, to be less than, to
 *         match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != '\0')
		{
			if ((unsigned char)s1[i] == (unsigned char)s2[i])
				i++;
			else
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
