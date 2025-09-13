/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:21:07 by radandri          #+#    #+#             */
/*   Updated: 2025/07/20 15:12:59 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
	{
		return (dstsize + src_len);
	}
	i = dst_len;
	j = 0;
	while (src[j] && (i + 1 < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	size_t ex;
// 	size_t ac;
// 	char dest_ex1[15] = "aabcant";
// 	char dest_ac2[15] = "aabcant";
// 	ex = strlcat(dest_ex1, "lorem", 2);
// 	ac = ft_strlcat(dest_ac2, "lorem", 2);

// 	printf("ex: %lu, ac: %lu\n", ex, ac);
// }