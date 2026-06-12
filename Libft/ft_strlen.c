/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:23:17 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:29:07 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// count str with I
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// #include <string.h>
// #include <stdio.h>
//
// int	main()
// {
// 	printf("Mine(size): %zu\n", ft_strlen("")); // should return 0
// 	printf("Mine(size): %zu\n", ft_strlen("Hello")); // should return 5
// 	printf("Mine(size): %zu\n", ft_strlen("123456789")); // return 9
// 	printf("Mine(size): %zu\n", ft_strlen("\0")); // return 0 
// 	// str contains null term so stops at '\0' hence len is 0 (empty str).
// 	printf("Theirs(size): %zu\n", strlen(""));
// 	printf("Theirs(size): %zu\n", strlen("Hello"));
// 	printf("Theirs(size): %zu\n", strlen("123456789"));
// 	printf("Theirs(size): %zu\n", strlen("\0"));
//
// 	// Special Cases
// 	printf("Mine: %zu\n", ft_strlen("Hellow world")); // should return 11
// 	printf("Mine: %zu\n", ft_strlen("123!@#")); // should return 6
// 	printf("Mine: %zu\n", ft_strlen("Hi\0Hidden")); // return 2
//
// 	// Edge Cases
// 	char longstr[1001];
// 	memset(longstr, 'a', 1000);
// 	longstr[1000] = '\0';
// 	printf("Mine: %zu\n", ft_strlen(longstr)); // expect 1000
// }