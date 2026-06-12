/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:36:09 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:21:06 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// duplicates str in to a new str
char	*ft_strdup(const char *src)
{
	char	*mem;
	int		i;

	i = 0;
	mem = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!mem)
		return (NULL);
	while (*src)
		mem[i++] = *src++;
	mem[i] = '\0';
	return (mem);
}

// #include <string.h>
// #include <stdio.h>
//
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;
//
// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }
//
// int main()
// {
// 	// Basic
// 	char *s = "Hello";
// 	char *dup = ft_strdup(s);
// 	printf("Orig: %s, Dup: %s\n", s, dup);
// 	free(dup);
//
// 	
// //	Empty
// 	char *dup2 = ft_strdup("");
// 	printf("empty String: '%s'\n", dup2); // single qoute to accent the emp
// 	free(dup2);
//
// Space and Sp Char
// 	char *dup3 = ft_strdup("  spaces  \n\t!");
// 	printf("Special: '%s'\n", dup3); 
// 	free(dup3);
//
// Very long
// 	char big[10000];
// 	int i = 0; 
// 	while (i < 9999)
// 	{
// 		big[i] = 'A';
// 		i++;
// 	}	
// 	big[9999] = '\0';
//	
// 	char *dup4 = ft_strdup(big);
// 	printf("Long str: %zu\n", strlen(dup4));
// 	free(dup4);
// }