/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:25:44 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:25:39 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'));
}

// #include <stdio.h> // printf
// #include <ctype.h> // (is) functions
//
// int main()
// {
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum('A'), !!isalnum('A'));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum('0'), !!isalnum('0'));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum('9'), !!isalnum('9'));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum('$'), isalnum('$'));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum('#'), isalnum('#'));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum(' '), isalnum(' '));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum(2), isalnum(2));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum(128), isalnum(128));
// 	printf("Mine/Output: %d | Theirs %d\n", ft_isalnum(-1), isalnum(-1));
// }