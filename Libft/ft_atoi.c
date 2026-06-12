/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 05:21:40 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:25:31 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// start with edge statements
// one dealing with White spaces and one with the Negatives
// then we'll have a loop statement to check for the first integer
// once found we use recursion to isolate the digit and convert it for print
// Var(s) i, sign ,  
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

//int	main(void)
//{
//	printf("%d", ft_atoi("------++-8746fdg"));
//}