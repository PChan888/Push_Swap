/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:11:04 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:27:16 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// writes a string of digits
void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	long	n;
	char	buf[12];

	i = 0;
	n = nb;
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
	{
		write (fd, &buf[i], 1);
	}
}

// #include <stdio.h>
//
// int main ()
// {
// 	ft_putnbr_fd(-678, 1);
// 	printf("\n");
// 	return(0);
// }