/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 03:24:45 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:28:48 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strjoin - concatenates two strings into a new string.
 * We need to allocate memory for the new string which is the sum of the
 * lengths of both strings plus one for the null terminator.
 * We then copy the first string into the new string, followed by the second
 * string, and finally add the null terminator at the end.*/
// @Sub memcpy for this to lower the time complexity from O(n^2) to O(n) and	
// less code.
// memcpy 1
// i = 0; 
// while (i < s1_len)
// {
// 	s[i] = s1[i];
// 	i++;
// }
// memcpy 2
// i = 0;
// while (i < s2_len)
// {
// 	s[s1_len + i] = s2[i];
// 	i++;
// }

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc(s1_len + s2_len + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, s1_len);
	ft_memcpy(s + s1_len, s2, s2_len);
	s[s1_len + s2_len] = '\0';
	return (s);
}

// #include <stdio.h>
// #include <stdlib.h>  // for free
//
// int main(void)
// {
//     char *s1;
//     char *s2;
//     char *result;
//
//     // Test 1: normal strings
//     s1 = "Hello";
//     s2 = "World";
//     result = ft_strjoin(s1, s2);
//     printf("Test 1: '%s'\n", result); // Expected: HelloWorld
//     free(result);
//
//     // Test 2: first string empty
//     s1 = "";
//     s2 = "World";
//     result = ft_strjoin(s1, s2);
//     printf("Test 2: '%s'\n", result); // Expected: World
//     free(result);
//
//     // Test 3: second string empty
//     s1 = "Hello";
//     s2 = "";
//     result = ft_strjoin(s1, s2);
//     printf("Test 3: '%s'\n", result); // Expected: Hello
//     free(result);
//
//     // Test 4: both strings empty
//     s1 = "";
//     s2 = "";
//     result = ft_strjoin(s1, s2);
//     printf("Test 4: '%s'\n", result); // Expected: ''
//     free(result);
//
//     // Test 5: strings with spaces or special characters
//     s1 = "Hi ";
//     s2 = "\tthere!";
//     result = ft_strjoin(s1, s2);
//     printf("Test 5: '%s'\n", result); // Expected: Hi \tthere!
//     free(result);
//
//     return 0;
// }