/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 05:20:13 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/25 02:16:53 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// make a static function so that it won't be accidentitally called outside the
// the current C file.
// i = (n <= 0); accounts for - and 0 and creates a count for it.
// Note: can add return (mem); 4 the "if (nbr == 0)" but would add 3 extra lines
static int	ft_nbrlen(int n)
{
	size_t	i;

	i = (n <= 0);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// mem to be allocated for int with malloc
char	*ft_itoa(int n)
{
	char	*mem;
	int		len;
	long	nbr;

	nbr = n;
	len = ft_nbrlen(n);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	mem[len] = '\0';
	if (nbr < 0)
	{
		mem[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		mem[0] = '0';
	while (nbr > 0)
	{
		mem[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (mem);
}

// can't start the int n with a "0" as octal (base 8) 0-7 9 doens't compile
// #include <stdio.h>
// int main()
// {
// 	int n = 987654;
// 	printf("%s\n", ft_itoa(n));
// }