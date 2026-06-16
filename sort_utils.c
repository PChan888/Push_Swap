/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 02:50:19 by kai               #+#    #+#             */
/*   Updated: 2026/06/17 02:50:22 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

// checks if stack is already sorted in ascending order
int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// Helper function for sort_five finds the position of 
// smallest number and rotate it to the top of Stack A.
void	find_min_pos(t_node *stack_a, int *min_val, int *min_pos)
{
	int		pos;
	t_node	*tmp;

	tmp = stack_a;
	*min_val = tmp->value;
	*min_pos = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->value < *min_val)
		{
			*min_val = tmp->value;
			*min_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

// pushes the smallest element of A to B
void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min_val;
	int	min_pos;

	find_min_pos(*stack_a, &min_val, &min_pos);
	while ((*stack_a)->value != min_val)
	{
		if (min_pos <= get_stack_size(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

// static void	push_min_to_b(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*tmp;
// 	int		min_val;
// 	int		min_pos;
// 	int		pos;

// 	tmp = *stack_a;
// 	min_val = tmp->value;
// 	pos = 0;
// 	min_pos = 0;
// 	while (tmp)
// 	{
// 		if (tmp->value < min_val)
// 		{
// 			min_val = tmp->value;
// 			min_pos = pos;
// 		}
// 		pos++;
// 		tmp = tmp->next;
// 	}
// 	while ((*stack_a)->value != min_val)
// 	{
// 		if (min_pos <= get_stack_size(*stack_a) / 2)
// 			ra(stack_a);
// 		else
// 			rra(stack_a);
// 	}
// 	pb(stack_a, stack_b);
// }
