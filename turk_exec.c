/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by kai               #+#    #+#             */
/*   Updated: 2026/06/17 02:49:44 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// -counting rotations to top for both stacks-
// by indexing to first or second half of stack size
// if index is less than half of stack size, return index (rotate up)
// if index is greater than half of stack size, return negative (rotate down)
// size(len) - index is the distance to rotate down
// midpoint is always rotated up
static int	rot_count(int index, int len)
{
	if (index <= len / 2)
		return (index);
	return (-(len - index));
}

// applies individual rotations for stack a or b, depending on flag.
static void	apply_rotation(t_node **stack, int *rot, int is_b)
{
	if (*rot > 0)
	{
		if (is_b)
			rb(stack);
		else
			ra(stack);
		(*rot)--;
	}
	else
	{
		if (is_b)
			rrb(stack);
		else
			rra(stack);
		(*rot)++;
	}
}

// determines rr or rrr, then applies remaining rotations for a and b.
static void	do_rotations(t_node **stack_a, t_node **stack_b,
				int rot_a, int rot_b)
{
	while ((rot_a > 0 && rot_b > 0) || (rot_a < 0 && rot_b < 0))
	{
		if (rot_a > 0)
		{
			rr(stack_a, stack_b);
			rot_a--;
			rot_b--;
		}
		else
		{
			rrr(stack_a, stack_b);
			rot_a++;
			rot_b++;
		}
	}
	while (rot_a != 0)
		apply_rotation(stack_a, &rot_a, 0);
	while (rot_b != 0)
		apply_rotation(stack_b, &rot_b, 1);
}

// used best node to determine the best push_cost and its target node,
// then calculates the rotations needed to bring both nodes to the top
// use rotations to bring both nodes to the top,
// then push the best node to the other stack.
void	push_best_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;
	int		rot_a;
	int		rot_b;

	best = get_min_cost_node(*stack_a);
	rot_a = rot_count(best->index, get_stack_size(*stack_a));
	rot_b = rot_count(best->target_node->index, get_stack_size(*stack_b));
	do_rotations(stack_a, stack_b, rot_a, rot_b);
	pb(stack_a, stack_b);
}

// used best node to determine the best push_cost and its target node,
// then calculates the rotations needed to bring both nodes to the top
// use rotations to bring both nodes to the top,
// then push the best node to the other stack.
void	push_best_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;
	int		rot_a;
	int		rot_b;

	best = get_min_cost_node(*stack_b);
	rot_b = rot_count(best->index, get_stack_size(*stack_b));
	rot_a = rot_count(best->target_node->index, get_stack_size(*stack_a));
	do_rotations(stack_a, stack_b, rot_a, rot_b);
	pa(stack_a, stack_b);
}
