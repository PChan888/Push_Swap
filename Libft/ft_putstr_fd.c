/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:03:55 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:27:24 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// outputs the string to specificed location
// fd kinda means which location
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
// 	char *s = "into";
// 	ft_putstr_fd(s, 1);
// }