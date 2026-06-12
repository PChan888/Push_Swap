/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:44:17 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:33:03 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function checks if the input is a character or not
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main()
// {
//     printf("Test with 'A': %d\n", ft_isalpha('A')); // should print 1
//     printf("Test with 'z': %d\n", ft_isalpha('z')); // should print 1
//     printf("Test with '9': %d\n", ft_isalpha('9')); // should print 0
//     printf("Test with '#': %d\n", ft_isalpha('#')); // should print 0
//     printf("Mine: %d | Theirs: %d\n", ft_isalpha('\n'), isalpha('\n')); 
// 	   should print 0
//     return 0;
// }