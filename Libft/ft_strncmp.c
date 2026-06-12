/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 02:34:43 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:22:01 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compares the two strings
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>
//
// int	main()
// {
// 	char *s1 = "beaver";
// 	char *s2 = "beard";
// 	size_t n = 3;
//	
// 	// doesn't have match
// 	printf("Result: %d\n", ft_strncmp(s1, s2, n)); // matches
// 	printf("Result: %d\n", ft_strncmp(s1, s2, 4)); // doesn't match
// 	return (0);
// }