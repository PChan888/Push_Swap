/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:48:28 by kai               #+#    #+#             */
/*   Updated: 2026/06/16 06:46:38 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Shifts all elements up by 1 position (First becomes Last).
 */
static void	rotate_nodes(t_node **stack)
{
	t_node	*first;
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = first;
	first->prev = tail;
	first->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate_nodes(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rotate_nodes(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	write(1, "rr\n", 3);
}
