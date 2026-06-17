/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:57:56 by kai               #+#    #+#             */
/*   Updated: 2026/06/17 08:22:23 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// assigns index and above_mid for each node in stack, used for cost analysis
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
		stack->index = i;
		if (i <= median)
			stack->above_mid = 1;
		else
			stack->above_mid = 0;
		stack = stack->next;
		i++;
	}
}

// Finds the node with the largest value in the stack
// because if there is no better match in stack_b for a node in stack_a
// we will push it to the position of the largest node in stack_b
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

// For each node in stack_a, find its landing spot in stack_b.
// Thats it.
// Finds the biggest value in stack_b that is smaller than current node
// in stack_a, if there is no smaller value, 
// find the biggest value in stack_b and set it as target
// best_match is the tracker to update the target.*
static void	set_target_a(t_node *stack_a, t_node *stack_b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match;

	while (stack_a)
	{
		best_match = LONG_MIN;
		target = NULL;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match)
			{
				best_match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

static void	set_costs_a(t_node *stack_a, int len_a, int len_b)
{
	int	rot_a;
	int	rot_b;

	while (stack_a)
	{
		if (stack_a->above_mid)
			rot_a = stack_a->index;
		else
			rot_a = len_a - stack_a->index;
		if (stack_a->target_node->above_mid)
			rot_b = stack_a->target_node->index;
		else
			rot_b = len_b - stack_a->target_node->index;
		if (stack_a->above_mid == stack_a->target_node->above_mid)
		{
			if (rot_a > rot_b)
				stack_a->push_cost = rot_a;
			else
				stack_a->push_cost = rot_b;
		}
		else
			stack_a->push_cost = rot_a + rot_b;
		stack_a = stack_a->next;
	}
}

void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = get_stack_size(stack_a);
	len_b = get_stack_size(stack_b);
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	set_costs_a(stack_a, len_a, len_b);
}

// // calculating push cost if above default if below midpoint
// // then subtrackng the index by stack size to get cost of rr or rrr
// // if the target node is above mid then we add the index of target
// // node to cost if below mid we subtract the index from stack size
// void	cost_analysis_a(t_node *stack_a, t_node *stack_b)
// {
// 	int	len_a;
// 	int	len_b;
//
// 	len_a = get_stack_size(stack_a);
// 	len_b = get_stack_size(stack_b);
// 	current_index(stack_a);
// 	current_index(stack_b);
// 	set_target_a(stack_a, stack_b);
// 	while (stack_a)
// 	{
// 		stack_a->push_cost = stack_a->index;
// 		if (!stack_a->above_mid)
// 			stack_a->push_cost = len_a - (stack_a->index);
// 		if (stack_a->target_node->above_mid)
// 			stack_a->push_cost += stack_a->target_node->index;
// 		else
// 			stack_a->push_cost += len_b - (stack_a->target_node->index);
// 		stack_a = stack_a->next;
// 	}
// }