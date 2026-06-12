/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_b_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by kai               #+#    #+#             */
/*   Updated: 2026/06/11 00:00:00 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_node	*get_min_cost_node(t_node *stack)
{
	t_node	*best;

	best = stack;
	while (stack)
	{
		if (stack->push_cost < best->push_cost)
			best = stack;
		stack = stack->next;
	}
	return (best);
}

static void	set_target_b(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match;

	while (stack_b)
	{
		best_match = LONG_MAX;
		target = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			stack_b->target_node = find_min(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	cost_analysis_b(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->index;
		if (!stack_b->above_median)
			stack_b->push_cost = len_b - (stack_b->index);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next;
	}
}
