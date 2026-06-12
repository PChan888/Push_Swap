/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 23:14:52 by kaichan           #+#    #+#             */
/*   Updated: 2026/01/26 20:24:21 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// move memory to the nth length of src to dst.
// if BOTH dst and src are NULL, return NULL
// type cast to unsigned char (non-negative)
// if d is lesser than s then it can iterate from the front
// else if d is greater than s then you iterate from the back
// otherwise it write over itself
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d <= s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (len--)
		{
			d[len] = s[len];
		}
	}
	return (dst);
}

// int main()
// {
// 	char dst[] = "yummy";
// 	char src[] = "yucky";
// 	size_t len = 3;
//
// 	printf("Before dst: %s\n", dst);
// 	ft_memmove(dst,src,len);
// 	printf("After dst: %s\n", dst);
//	
// 	return(0);
// }