/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:37:17 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:25:07 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <string.h>
// #include <stdio.h>
//
// int 	main()
// {
// 	// test - small buffer
// 	char	buf1[6] = "Hello"; 
// 	ft_memset(buf1, 'x', 4);
// 	buf1[5] = '\0';
// 	printf("Mine: %s\n", buf1); // expect xxxxo
//
// 	// test - zero size
// 	char	buf2[6] = "Hello"; 
// 	ft_memset(buf2, 'y', 0);
// 	buf2[5] = '\0';
// 	printf("Mine: %s\n", buf2); // expect Hello (nothing changed)
//
// 	// test - fill whole buffer
// 	char buf3[6];
// 	ft_memset(buf3, 'z', 5);
// 	printf("Mine: %s\n", buf3);
//
// 	// test - larger buf
// 	char buf4[1000];
// 	ft_memset(buf4, 'a', 1000);
// 	int i;
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%c", buf4[i]);
// 		i++;
// 	}
// 	printf("\n");
//
// 	// test 5 - 
// 	char buf5[6] = "Hello";
// 	ft_memset(buf5 + 4, 'Z', 1);
// 	printf("Mine: %s\n", buf5);
// }