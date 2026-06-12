/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 19:07:41 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:26:40 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// calloc allocates and zeros out the memory 
// @count index for the arr
// @size length/size of the string
// if (box_size != 0 && count_of_box > (Room_size / Size_of_box))
// @(size_t)-1 is the max size of the room to allocate space for box
void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;
	size_t	len;

	if (size != 0 && count > ((size_t)-1 / size))
		return (NULL);
	len = count * size;
	arr = malloc(len);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, len);
	return (arr);
}

// int main ()
// {
// 	printf("sizeof int = %d\n", sizeof(int));
// 	// printf("%s\n", ft_calloc( 3, 5));
// 	// printf("%s\n", ft_calloc( 3, 5));
// 	printf("sizeof char = %d\n", sizeof(char));
// 	printf("sizeof long = %d\n", sizeof(long));
// 	printf("sizeof long long = %d\n", sizeof(long long));
// 	printf("sizeof unsigned int = %d\n", sizeof(unsigned int));
// 	printf("sizeof size_t = %d\n", sizeof(size_t));
// 	printf("sizeof void = %d\n", sizeof(void));
// 	printf("sizeof short = %d\n", sizeof(short));
// 	printf("sizeof double = %d\n", sizeof(double));
// 	printf("sizeof int128_t = %d\n", sizeof(_BitInt(128)));
// }