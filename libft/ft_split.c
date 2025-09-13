/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:10:22 by radandri          #+#    #+#             */
/*   Updated: 2025/07/21 00:22:09 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	in_word;
	int	word;

	i = 0;
	in_word = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			word++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (word);
}

static char	*next_word(const char *s, char c, int *start)
{
	int	i;
	int	len;

	i = *start;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	*start = i;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (ft_substr(s, *start, len));
}

static int	freee(char **res, char *word, int j)
{
	if (!word)
	{
		while (j > 0)
			free(res[--j]);
		free(res);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		count;
	char	*word;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	count = word_count(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (NULL);
	while (j < count)
	{
		word = next_word(s, c, &i);
		if (freee(res, word, j))
			return (NULL);
		res[j++] = word;
		i += ft_strlen(word);
	}
	res[j] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	**res;

// 	res = ft_split("hello world test", ' ');
// 	for (int i = 0; res[i]; i++)
// 		printf("[%s]\n", res[i]);
// 	// Pense à free ici si nécessaire
// 	return (0);
// }
