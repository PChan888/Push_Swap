/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 23:24:28 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:29:59 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// is_in_set checks for the characters in the set to be trimmed
//
// @c is the characters from the string that checks the char from the set
// @set is the the set of chars to be trimmed.
static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
 * Allocates memory (using malloc(3)) and returns a
 * copy of ’s1’ with characters from ’set’ removed
 * from the beginning and the end
 * 
 * @param s1 : string that needs to be trimmed
 * @param set : set of characters to trim
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		trimmed_str[i] = s1[start + i];
		i++;
	}
	trimmed_str[end - start] = '\0';
	return (trimmed_str);
}

// int main()
// {
// 	char* s1 = "qweXXXXqweXXXXXewq";
// 	char* set = "qwe";
// 	char* result = ft_strtrim(s1, set);

// 	printf("%s\n", result);
// 	return (0);
// }