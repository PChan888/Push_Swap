/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:23:48 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:28:09 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// find char "c" in str
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char)c == s[i])
		return ((char *) &s[i]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
//
// int main()
// {
// 	char *s = "hello";
// 	printf("Mine: %s\n", ft_strchr(s, 'e')); // ello
//
// 	printf("Mine: %s\n", ft_strchr(s, 'z')); // Null
//
// 	printf("Mine: %s\n", ft_strchr(s, '\0')); // ptr to '\0'
//
// 	char *b = "bananas";
// 	printf("Mine: %s\n", ft_strchr(b, 'a')); // first 'a'
//
// 	printf("Mine: %s\n", ft_strchr("", 'a')); // Null
// 	printf("Mine: %s\n", ft_strchr("", '\0')); // ptr to empty
//
// 	// edge values
// 	printf("Mine: %s\n", ft_strchr("abc", 256)); // out-of-range int (iffy)
// 	printf("Mine: %s\n", ft_strchr("abc", -1)); // negative int (iffy)
// }