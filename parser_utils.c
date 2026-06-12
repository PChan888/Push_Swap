/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:50:57 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 01:03:21 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper 1: Counts total tokens across all input arguments */
int	get_flatten_count(int argc, char **argv)
{
	int		digit_count;
	int		i;
	int		j;
	char	**new;

	digit_count = 0;
	i = 1;
	while (i < argc)
	{
		new = ft_split(argv[i], ' ');
		if (!new)
			return (-1);
		j = 0;
		while (new[j] != NULL)
		{
			digit_count++;
			free(new[j]);
			j++;
		}
		free(new);
		i++;
	}
	return (digit_count);
}

/* Helper 2: Populates the flat array with string pointers from ft_split */
void	mixed_fill(char **flat_array, char **argv, int argc)
{
	char	**new;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		new = ft_split(argv[i], ' ');
		j = 0;
		while (new && new[j] != NULL)
			flat_array[k++] = new[j++];
		free(new);
		i++;
	}
	flat_array[k] = NULL;
}

/*Helper 3: Validates if a string is a properly formatted 
integer within range */
int	is_valid_int(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i++] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-result) < INT_MIN))
			return (0);
	}
	return (1);
}

/* Helper 4: Frees the temporary char** string array layout */
void	free_flat_array(char **flat_array)
{
	int	i;

	if (!flat_array)
		return ;
	i = 0;
	while (flat_array[i])
	{
		free(flat_array[i]);
		i++;
	}
	free(flat_array);
}
