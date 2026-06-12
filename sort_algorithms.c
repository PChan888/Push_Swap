/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:10:14 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 01:02:23 by kaichan          ###   ########.fr       */
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
		sa(stack_a, 1);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		large_sort(stack_a, stack_b);
}

/*
** Hardcoded puzzle solver for exactly 3 numbers.
** Since there are only 5 unsorted configurations, we can 
** always solve this in a maximum of 2 moves.
*/
void	sort_three(t_node **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->value;
	mid = (*stack_a)->next->value;
	bot = (*stack_a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(stack_a, 1);
	else if (top > mid && mid > bot)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(stack_a, 1);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(stack_a, 1);
}

/*
** Helper function for sort_five to find the position of the 
** smallest number and rotate it to the top of Stack A.
*/
static void	find_min(t_node *stack_a, int *min_val, int *min_pos)
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

void	push_min_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min_val;
	int	min_pos;

	find_min(*stack_a, &min_val, &min_pos);
	while ((*stack_a)->value != min_val)
	{
		if (min_pos <= get_stack_size(*stack_a) / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
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
// 			ra(stack_a, 1);
// 		else
// 			rra(stack_a, 1);
// 	}
// 	pb(stack_a, stack_b, 1);
// }

/*
** Optimized shortcut for 4 to 5 numbers to secure "Kudos" points.
** It safely strips the smallest elements until only 3 are left,
** calls sort_three, and pops them straight back.
*/
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 5)
		push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

/*
** large_sort() (the Turk Sort for stacks larger than 5) is implemented
** in large_sort.c, using the cost-analysis helpers from turk_utils.c,
** turk_b_utils.c and turk_exec.c.
*/
