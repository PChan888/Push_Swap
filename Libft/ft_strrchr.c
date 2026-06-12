/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:42:20 by kaichan           #+#    #+#             */
/*   Updated: 2026/01/28 22:17:47 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns the string of the last occurence of particular char 
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// int main()
// {
// 	char *h = "Kneeling";
// 	int c	= 'e';
//
// 	printf("%s\n", ft_strrchr(h, c));
// 	printf("%s\n", ft_strrchr(h, 'l'));
// 	return (0);
// }