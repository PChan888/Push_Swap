/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:57:56 by kai               #+#    #+#             */
/*   Updated: 2026/06/10 21:58:32 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = get_stack_size(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i; // Assigns 0, 1, 2, 3...
		if (i <= median)
			stack->above_median = 1; // Top half
		else
			stack->above_median = 0; // Bottom half
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match_idx;

	while (stack_a)
	{
		best_match_idx = LONG_MIN;
		target = NULL;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value 
				&& current_b->value > best_match_idx)
			{
				best_match_idx = current_b->value;
				target = current_b; // Temporary hold of the node pointer
			}
			current_b = current_b->next;
		}
		// If no smaller number exists, target is the absolute maximum of B
		if (best_match_idx == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target; // Lock the pointer bridge!
		stack_a = stack_a->next;
	}
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	current_index(stack_a); // Refresh A's indexes
	current_index(stack_b); // Refresh B's indexes
	set_target_a(stack_a, stack_b); // Connect the target pointers
	while (stack_a)
	{
		// Cost for Node A to reach top of Stack A
		stack_a->push_cost = stack_a->index;
		if (!stack_a->above_median)
			stack_a->push_cost = len_a - (stack_a->index);
		// Cost for Target B to reach top of Stack B
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

t_node	*find_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	while (stack)
	{
		if (stack->value > max->value)
			max = stack;
		stack = stack->next;
	}
	return (max);
}