/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:29:26 by radandri          #+#    #+#             */
/*   Updated: 2025/08/24 10:43:51 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * This fct takes a string and writes it to the given fd. If the string is NULL,
 * the function returns 0. If the write operation fails, the fctn ret -1.
 *
 * @param s The string to be written. If NULL, the function returns 0.
 * @param fd The file descriptor to which the string is written.
 *
 * @return The length of the string written on success, 0 if the string is NULL,
 *         or -1 if the write operation fails.
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (write(fd, s, len) < 0)
		return (-1);
	return (len);
}
