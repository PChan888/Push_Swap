/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:06:44 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:25:49 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h> // (is) functions
//
// int main()
// {
// 	// !! hides bitmask style
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('a'), !!isdigit('a'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('A'), !!isdigit('A'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('!'), !!isdigit('!'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit(120), !!isdigit(120));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('#'), !!isdigit('#'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('0'), !!isdigit('0'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit(0), isdigit(0));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit('9'), isdigit('9'));
// 	printf("Mine: %d | Theirs: %d\n", ft_isdigit(9), isdigit(9));
// }