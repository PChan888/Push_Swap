/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 00:00:00 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 00:58:45 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the signed rotation distance for a node at "index" in a
** stack of size "len": positive means "index" rotations up (ra/rb),
** negative means abs(value) rotations down (rra/rrb).
*/
static int	rot_count(int index, int len)
{
	if (index <= len / 2)
		return (index);
	return (-(len - index));
}

static void	apply_rotation(t_node **stack, int *rot, int is_b)
{
	if (*rot > 0)
	{
		if (is_b)
			rb(stack, 1);
		else
			ra(stack, 1);
		(*rot)--;
	}
	else
	{
		if (is_b)
			rrb(stack, 1);
		else
			rra(stack, 1);
		(*rot)++;
	}
}

static void	do_rotations(t_node **stack_a, t_node **stack_b,
				int rot_a, int rot_b)
{
	while ((rot_a > 0 && rot_b > 0) || (rot_a < 0 && rot_b < 0))
	{
		if (rot_a > 0)
		{
			rr(stack_a, stack_b, 1);
			rot_a--;
			rot_b--;
		}
		else
		{
			rrr(stack_a, stack_b, 1);
			rot_a++;
			rot_b++;
		}
	}
	while (rot_a != 0)
		apply_rotation(stack_a, &rot_a, 0);
	while (rot_b != 0)
		apply_rotation(stack_b, &rot_b, 1);
}

void	push_best_to_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;
	int		rot_a;
	int		rot_b;

	best = get_min_cost_node(*stack_a);
	rot_a = rot_count(best->index, get_stack_size(*stack_a));
	rot_b = rot_count(best->target_node->index, get_stack_size(*stack_b));
	do_rotations(stack_a, stack_b, rot_a, rot_b);
	pb(stack_a, stack_b, 1);
}

void	push_best_to_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*best;
	int		rot_a;
	int		rot_b;

	best = get_min_cost_node(*stack_b);
	rot_b = rot_count(best->index, get_stack_size(*stack_b));
	rot_a = rot_count(best->target_node->index, get_stack_size(*stack_a));
	do_rotations(stack_a, stack_b, rot_a, rot_b);
	pa(stack_a, stack_b, 1);
}
