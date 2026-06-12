/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:11:13 by kaichan           #+#    #+#             */
/*   Updated: 2026/01/25 15:49:33 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// takes the string and interates through filling the string with 0 to limit
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// int main()
// {
// 	char s[] = "hello";
// 	int n = 3;
//	
// 	ft_bzero(s, n);
// 	printf("Result: %s\n", s);
// 	printf("Result [3]%c\n", s[3]);
// 	return(0);
// }