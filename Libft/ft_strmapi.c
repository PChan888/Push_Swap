/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:14:44 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:29:17 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// modifies string with function and outputs new string while old str is intact
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!s)
		return (ft_strdup(""));
	if (!f)
		return (ft_strdup(s));
	new = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

// // tester:
// #include <stdio.h>
// #include <stdlib.h>
//
// char rot3(unsigned int i, char c)
// {
// 	(void)i;
//     return (c + 3);
// }
//
// int main(void)
// {
//     char str[] = "hello";
//
//     char *new = ft_strmapi(str, rot3);
//     printf("Original: %s\n", str);
// 	printf("Result: %s\n", new);
// 	free(new);
//	
//     return 0;
// }