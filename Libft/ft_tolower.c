/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:20:39 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:30:17 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// converts only 1 chars
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// #include <stdio.h> // printf
// #include <ctype.h> // (is) functions
//
// int main()
// {
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower('A'), tolower('A'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower('a'), tolower('a'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower('0'), tolower('0'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower('9'), tolower('9'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower(65), tolower(65));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_tolower(32), tolower(32));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_tolower('0'), tolower('0'));
// }