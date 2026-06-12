/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:58:05 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:30:22 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <stdio.h> // printf
// #include <ctype.h> // (is) functions
//
// int main()
// {
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper('A'), toupper('A'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper('a'), toupper('a'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper('0'), toupper('0'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper('9'), toupper('9'));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper(65), toupper(65));
// 	printf("Mine/Output: %c | Theirs %c\n", ft_toupper(32), toupper(32));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_toupper('0'), toupper('0'));
// }