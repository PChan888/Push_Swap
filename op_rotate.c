/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:48:28 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 01:01:21 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Shifts all elements up by 1 position (First becomes Last).
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

void	ra(t_node **stack_a, int print_flag)
{
	rotate_nodes(stack_a);
	if (print_flag)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, int print_flag)
{
	rotate_nodes(stack_b);
	if (print_flag)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, int print_flag)
{
	rotate_nodes(stack_a);
	rotate_nodes(stack_b);
	if (print_flag)
		write(1, "rr\n", 3);
}
