/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:50:24 by kai               #+#    #+#             */
/*   Updated: 2026/06/10 20:50:55 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Shifts all elements down by 1 position (Last becomes First).
 */
static void	rev_rotate_nodes(t_node **stack)
{
	t_node	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rra(t_node **stack_a, int print_flag)
{
	rev_rotate_nodes(stack_a);
	if (print_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b, int print_flag)
{
	rev_rotate_nodes(stack_b);
	if (print_flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b, int print_flag)
{
	rev_rotate_nodes(stack_a);
	rev_rotate_nodes(stack_b);
	if (print_flag)
		write(1, "rrr\n", 4);
}