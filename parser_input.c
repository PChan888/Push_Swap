/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 02:01:36 by kai               #+#    #+#             */
/*   Updated: 2026/06/09 21:34:51 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 1. Empty / whitespace-only input check
// 2. Tokenization (split by spaces, no empty tokens) check
// 3. Mixed input handling (argv strings containing multiple numbers) check
// 4. Valid integer format ([+/-]?[0-9]+)
// 5. Safe conversion (detect overflow, reject partial parsing)
// 6. Range validity (INT_MIN / INT_MAX)
// 7. Normalization (e.g. +0, -0, 000123)
// 8. Duplicate detection (on normalized integers)
// 1. Input handling / splitting
// Covers:
// Empty / whitespace-only input
// Tokenization (split by spaces, no empty tokens)
// Mixed input handling (argv strings containing multiple numbers)
// 2. Format validation
// Covers:
// Valid integer format ([+/-]?[0-9]+)
// 3. Safe conversion + range check
// Covers:
// Safe conversion (detect overflow, reject partial parsing)
// Range validity (INT_MIN / INT_MAX) 
// Normalization (e.g. +0, -0, 000123)
// 4. Duplicate detection
// Covers:
// Duplicate detection (on normalized integers)
// 5. Orchestrator (parser controller)
// Covers:
// Calls all steps in order
// Loops through tokens
// Builds final integer array


char	**input_split_and_flatten(int argc, char **argv)
{
	char	**flat_array;
	int		digit_count;

	digit_count = get_flatten_count(argc, argv);
	if (digit_count <= 0)
		return (NULL);
	flat_array = malloc(sizeof(char *) * (digit_count + 1));
	if (!flat_array)
		return (NULL);
	mixed_fill(flat_array, argv, argc);
	return (flat_array);
}

//(rewrite later)
int check_array_and_dup(char **flat_array)
{
    int i;
    int j;

    i = 0;
    while (flat_array[i] != NULL)
    {
        if (!is_valid_int(flat_array[i]))
        {
            free_flat_array(flat_array);
            error_exit();
        }
        j = 0;
        while (j < i)
        {
            if (ft_atoi(flat_array[i]) == ft_atoi(flat_array[j]))
            {
                free_flat_array(flat_array);
                error_exit();
            }
            j++;
        }
        i++;
    }
    return (1);
}

t_node *build_doubly_stack(char **flat_array)
{
    t_node *stack_a;
    t_node *new_node;
    int     i;

    stack_a = NULL;
    i = 0;
    while (flat_array[i] != NULL)
    {
        new_node = lst_new(ft_atoi(flat_array[i]));
        if (!new_node)
        {
            free_stack(&stack_a); 
            free_flat_array(flat_array);
            error_exit();
        }
        lst_add_back(&stack_a, new_node);
        i++;
    }
    return (stack_a);
}

// int	safe_convert(const char *str, int *error_flag)
// {
// 	int			i;
// 	int			sign;
// 	long long	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i++] == '-')
// 			sign = -1;
// 	}
// 	if (str[i] == '\0' || (str[i] < '0' || str[i] > '9'))
// 		return (0);
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		result = result * 10 + (str[i++] - '0');
// 		if ((sign == 1 && result > INT_MAX) 
// 			|| (sign == -1 && (-result) < INT_MIN))
// 			return (0);
// 	}
// 	return ((int)(result * sign));
// }

// int	is_valid_and_convert(const char *str, int *out_value)
// {
// 	int			i;
// 	int			sign;
// 	long long	result;

// 	i = 0;
// 	sign = 1;
// 	result = 0;

// 	if (str[i++] == '-')
// 		sign = -1;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	if (str[i] == '\0')
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 		result = result * 10 + (str[i++] - '0');
// 		if ((sign == 1 && result > INT_MAX) 
// 			|| (sign == -1 && (-result) < INT_MIN))
// 			return (0);
// 	}
// 	*out_value = (int)(result * sign);
// 	return (1);
// }

// int	check_duplicates(char **flat_array)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (flat_array[i])
// 	{
// 		j = i + 1;
// 		while (flat_array[j])
// 		{
// 			if (ft_strcmp(flat_array[i], flat_array[j]) == 0)
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	*store_numbers(char **flat_array, int *total_count, int *error_flag)
// {
// 	int	*int_array;
// 	int	i;

// 	i = 0;
// 	while (flat_array[i])
// 		i++;
// 	*total_count = i;
// 	if (check_duplicates(flat_array))
// 		return (*error_flag = 1, NULL);
// 	int_array = malloc(sizeof(int) * (*total_count));
// 	if (!int_array)
// 		return (*error_flag = 1, NULL);
// 	i = 0;
// 	while (flat_array[i])
// 	{
// 		if (!is_valid_token(flat_array[i]))
// 			return (free(int_array), *error_flag = 1, NULL);
// 		int_array[i] = safe_convert(flat_array[i], error_flag);
// 		if (*error_flag)
// 			return (free(int_array), NULL);
// 		i++;
// 	}
// 	return (int_array);
// }
