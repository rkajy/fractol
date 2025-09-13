/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:04:46 by radandri          #+#    #+#             */
/*   Updated: 2025/07/10 22:41:40 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*array;
	unsigned char	copy;
	int				i;

	array = (char *)(b);
	copy = (unsigned char)c;
	i = 0;
	while (i <= (int)len - 1)
	{
		array[i] = copy;
		i++;
	}
	return (b);
}

// #include <string.h>
// int main(void)
// {
//     char str[50] = "GeeksForGeeks is for programming geeks.";
//     printf("\nBefore memset(): %s\n", str);

//     // Fill 8 characters starting from str[13] with '.'
//     ft_memset(str + 13, '.', 8*sizeof(char));

//     printf("After memset():  %s", str);
//     return (0);
// }