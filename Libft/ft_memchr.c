/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 03:40:05 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:26:13 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// look for first occurance of c in the first n bytes 
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	size_t			j;

	i = (unsigned char *)s;
	j = 0;
	while (j < n)
	{
		if (i[j] == (unsigned char) c)
			return ((void *)(i + j));
		j++;
	}
	return (NULL);
}

// int main()
// {
// 	char *s = "bubblegum";
// 	int c = 'b';
//
// 	printf("Result: ")
// }