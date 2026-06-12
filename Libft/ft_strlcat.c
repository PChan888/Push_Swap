/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:33:46 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/24 15:30:09 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Replacing one string on to another with a limited character size
// appends the NUL-terminated string src to the end of dst
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] && (dst_len + i < dstsize -1))
	{
		dst[dst_len + i] = src [i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/* 
int main(void)
{
    char buffer[10] = "Hi";
    size_t result;

    result = ft_strlcat(buffer, "There", sizeof(buffer));
    printf("Result: %zu\n", result);
    printf("Buffer: '%s'\n", buffer);

    return 0;
}
*/