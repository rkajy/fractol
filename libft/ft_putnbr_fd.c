/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:38:13 by radandri          #+#    #+#             */
/*   Updated: 2025/07/20 20:32:32 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			arr[10];
	int				j;
	unsigned int	result;

	if (n < 0)
		result = -n;
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else
		result = n;
	j = 9;
	while (result > 0)
	{
		arr[j--] = (result % 10) + '0';
		result = result / 10;
	}
	if (n < 0)
		write(fd, "-", 1);
	while (j + 1 < 10)
		write(fd, &arr[(j++) + 1], 1);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_putnbr_fd(1, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(5, 1);
// 	write(1, "\n", 1);

// 	ft_putnbr_fd(-88, 1);
// 	write(1, "\n", 1);

// 	ft_putnbr_fd(11, 1);
// 	write(1, "\n", 1);

// 	ft_putnbr_fd(42, 1);
// 	write(1, "\n", 1);

// 	ft_putnbr_fd(2147483647, 1);
// 	write(1, "\n", 1);

// 	ft_putnbr_fd(-2147483648, 1);

// 	return (0);
// }