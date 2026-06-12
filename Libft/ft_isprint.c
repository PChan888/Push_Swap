/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:14:23 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:26:31 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for printable characters ie: not [NULL], [DEL].
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// #include <ctype.h>
//
// int	main()
// {
// 	printf("Mine: %d | %d\n", ft_isprint('A'), !!isprint('A'));
// 	printf("Mine: %d | %d\n", ft_isprint(' '), !!isprint(' '));
// 	printf("Mine: %d | %d\n", ft_isprint('9'), !!isprint('9'));
// 	printf("Mine: %d | %d\n", ft_isprint('#'), !!isprint('#'));
// 	printf("Mine: %d | %d\n", ft_isprint(12), !!isprint(12));
// 	printf("Mine: %d | %d\n", ft_isprint(128), isprint(128));
// 	printf("Mine: %d | %d\n", ft_isprint(90), !!isprint(90));
// }