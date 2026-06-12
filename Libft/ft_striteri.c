/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 02:13:10 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:27:48 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* apply the function f to the character at index i
 * passing i and the address to s[i] as parameter to f
 * f will update the original string directly */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// for referrence
// int	ft_toupper(int c)
// {
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }
//
// Test to_upper my code
// #include <stdio.h>
// void rot3(unsigned int i, char *c)
// {
// 	(void)i;
//     *c += 3;
// }
//
// int main(void)
// {
//     char str[] = "hello";
//
//     ft_striteri(str, rot3);
//     printf("Result: %s\n", str);
//     return 0;
// }
//
// GPT
// #include <stdio.h>
//
// // Example function to make letters uppercase
// void to_upper(unsigned int i, char *c)
// {
//     (void)i;
//     if (*c >= 'a' && *c <= 'z')
//         *c = *c - 32;
// }
//
// // Example function: add index to character
// void add_index(unsigned int i, char *c)
// {
//     *c = *c + i;
// }
//
// // Example no-op function
// void do_nothing(unsigned int i, char *c)
// {
//     (void)i;
//     (void)c;
// }
//
// int main(void)
// {
//     char str1[] = "hello";
//     char str2[] = "abc";
//     char str3[] = "";
//     char str4[] = "xyz";
//
//     // Test 1: simple uppercase
//     ft_striteri(str1, to_upper);
//     printf("Test 1 (uppercase): %s\n", str1); // HELLO
//
//     // Test 2: add index to letters
//     ft_striteri(str2, add_index);
//     printf("Test 2 (add index): %s\n", str2); // a->a, b->c, c->e => ace
//
//     // Test 3: empty string
//     ft_striteri(str3, to_upper);
//     printf("Test 3 (empty string): '%s'\n", str3); // ''
//
//     // Test 4: do nothing
//     ft_striteri(str4, do_nothing);
//     printf("Test 4 (do nothing): %s\n", str4); // xyz
//
//     // Test 5: spaces and special characters
//     char str5[] = " a b\n!";
//     ft_striteri(str5, to_upper);
//     printf("Test 5 (spaces/special): '%s'\n", str5); // ' A B\n!'
//	
// 	return 0;
// }