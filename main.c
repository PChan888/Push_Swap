/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 00:21:10 by kaichan           #+#    #+#             */
/*   Updated: 2026/06/06 01:29:16 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// parser will first check for full string input or  multiple arguments or mix
// of both. It will then validate the input, ensuring that all values are
// first integers, then check for duplicates, and
// finally fill stack_a with the valid integers.

/*
** Original placeholder main, kept for review.
** Replaced because parse_input() did not exist: input_split_and_flatten,
** check_array_and_dup and build_doubly_stack are now called directly below.
**
int main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return(0);

	// parse_input meaning: it will take the command line arguments, validate
	// them (check if they are integers, check for duplicates, etc.) and then
	// fill stack_a with the valid integers. If there is any error during
	// parsing (like invalid input), it will return false, and we will print
	// "Error" to stderr and exit with a non-zero status.
	if (!parse_input(argc, argv, &stack_a)) // parse_input will validate and fill stack_a
	{
		write(2, "Error\n", 6);
		return(1);
	}


}
*/

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**flat_array;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	flat_array = input_split_and_flatten(argc, argv);
	if (!flat_array)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	check_array_and_dup(flat_array);
	stack_a = build_doubly_stack(flat_array);
	free_flat_array(flat_array);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}