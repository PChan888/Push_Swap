/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by kai               #+#    #+#             */
/*   Updated: 2026/06/11 00:00:00 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotates stack_a (cheapest direction) so that its smallest value
** ends up on top, leaving the result fully sorted.
*/
void	finalize_rotation(t_node **stack_a)
{
	t_node	*min;
	int		rot;

	current_index(*stack_a);
	min = find_min(*stack_a);
	rot = min->index;
	if (min->index > get_stack_size(*stack_a) / 2)
		rot = -(get_stack_size(*stack_a) - min->index);
	while (rot > 0)
	{
		ra(stack_a, 1);
		rot--;
	}
	while (rot < 0)
	{
		rra(stack_a, 1);
		rot++;
	}
}

/*
** The Brain of the Turk Sort for stacks larger than 5.
** Phase 1: repeatedly send the cheapest element of A to its best
** spot in B, until only 3 remain in A, then sort those with sort_three.
** Phase 2: repeatedly bring back the cheapest element of B to its
** best spot in A, then do a final rotation to fully sort A.
*/
void	large_sort(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	while (get_stack_size(*stack_a) > 3)
	{
		cost_analysis_a(*stack_a, *stack_b);
		push_best_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		cost_analysis_b(*stack_a, *stack_b);
		push_best_to_a(stack_a, stack_b);
	}
	finalize_rotation(stack_a);
}
