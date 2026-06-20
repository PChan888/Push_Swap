/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:10:14 by kai               #+#    #+#             */
/*   Updated: 2026/06/20 14:09:40 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size <= 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
}

// Rotates stack_a (cheapest direction) so that its smallest value
// ends up on top, leaving the result fully sorted.
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
		ra(stack_a);
		rot--;
	}
	while (rot < 0)
	{
		rra(stack_a);
		rot++;
	}
}

// Hardcoded puzzle solver for exactly 3 numbers.
// Since there are only 5 unsorted configurations, we can 
// always solve this in a maximum of 2 moves.
void	sort_three(t_node **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->value;
	mid = (*stack_a)->next->value;
	bot = (*stack_a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(stack_a);
	else if (top > mid && mid > bot)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack_a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack_a);
}

// Optimized shortcut for 4 to 5 numbers
// It safely moves the smallest elements to b until only 3 are left,
// calls sort_three, then pops b straight back.
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 5)
		push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

// The Brain of the Turk Sort for stacks larger than 5.
// Phase 1: repeatedly send the cheapest element of A to its best
// spot in B, until only 3 remain in A, then sort those with sort_three.
// Phase 2: repeatedly bring back the cheapest element of B to its
// best spot in A, then do a final rotation to fully sort A.
void	large_sort(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
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
