/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 04:49:25 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/25 17:19:20 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// put a char
// write fd  is file des, &c is the mbuffer, and 1 is byte.
// @ char c character to print
// @ int fd file des 0 input, 1 output, 2 error or higher.
// Functions like ft_putchar_fd let you use this system to write to different 
// outputs, not just the terminal.
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
// 	ft_putchar_fd('t', 0);
// 	return (0);
// }
// int main()
// {
// 	ft_putchar_fd('t', 1);
// 	return (0);
// }