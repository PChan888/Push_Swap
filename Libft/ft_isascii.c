/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:47:56 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/22 04:17:15 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h> 	// These functions are designed to work with single
// 					// characters, typically represented as int values
// 					// corresponding to their ASCII or extended character
// 					// set values.
// int main()
// {
// 	printf("Mine: %d | Theirs %d\n", ft_isascii('A'), isascii('A'));
// 	// checks with single qoute (Integer Value Of) converts to Ascii Int Val
// 	printf("Mine: %d | Theirs %d\n", ft_isascii(65), isascii(65));
// 	// Checks with digits (Int Val)
// 	printf("Mine: %d | Theirs %d\n", ft_isascii(128), isascii(128)); 
// 	// checks for over 127
// 	printf("Mine: %d | Theirs %d\n", ft_isascii(-1), isascii(-1));
// 	// Checks for under 0
// 	return(0);
// 	// Good practice
// }