/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:26:29 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:29:52 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// return a str to the first occurance of the str n found in the limited size
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*h;
	unsigned char	*n;
	size_t			i;
	size_t			j;

	h = (unsigned char *)haystack;
	n = (unsigned char *)needle;
	if (*n == '\0')
		return ((char *)h);
	i = 0;
	while (i < len && h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && (i + j) < len)
		{
			j++;
			if (n[j] == '\0')
				return ((char *)&h[i]);
		}
		i++;
	}
	return (NULL);
}

/*Failed attempt:
 #include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{

	if (*n == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (i < len)
	{
		while (h[i] == n[j])
		{
			start = i;
			while (h[i] == n[j])
			{
				i++;
				j++;
				if (h[i] != n[j])
				{
					j = 0;
				}
				if (n[j] == '\0')
					return (&h[start]);
			}
		}
		i++;
	}
	return (NULL);
}
I believed I need a temp so I can return the start of when
 the match began but caused more issues

*/
//
// #include <stdio.h>
// #include <stdlib.h> don't need
// #include <string.h> don't need
//
// int main()
// {
// 	char *h = "Kneeling";
// 	char *n	= "el";
//	
// 	printf("%s\n", ft_strnstr(h, n, 4)); // reads till e
// 	printf("%s\n", ft_strnstr(h, n, 5)); // reads till el
// 	return (0);
// }	