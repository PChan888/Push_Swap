/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 03:20:08 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:22:58 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* substr - finds a string with-in a string and returns the length asked.
 * Extracts part of a string based on a starting position (start) and 
 * the number of characters to extract (length).
 * When start is greater than str's length we return with strdup so it returns 
 * an empty string and so it can be easily freed later. 
 * another instance is when len is greater than the size of *s 
 * in this instance you just substract the start fromt he string's length
 * so you can return everything after the start because len > s_len.
 * we need a dest <-- for printing. what do we print? the sublength of the 
 * string. We allocate memory for copying *s over.*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main()
// {
// 	char *s = "hello world";
// 	int start = 3;
// 	size_t len = 3;
//	
// 	printf(" %s\n", ft_substr(s, start , len));
// 	return (0); // "lo "
// }