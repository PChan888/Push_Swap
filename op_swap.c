/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:47:23 by kai               #+#    #+#             */
/*   Updated: 2026/06/17 02:40:23 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Safely swaps the first two nodes of a doubly linked list.
 * 1. Disconnects second node from third node (if it exists).
 * 2. Swaps next/prev links between first and second nodes.
 * 3. Updates the new first node's prev pointer to NULL.
 * 4. Updates the stack pointer to point to the new head.
 */
static void	swap_nodes(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

/**
 * Swaps the first 2 elements at the top of stack a.
 */
void	sa(t_node **stack_a)
{
	swap_nodes(stack_a);
	write(1, "sa\n", 3);
}

/**
 * Swaps the first 2 elements at the top of stack b.
 */
void	sb(t_node **stack_b)
{
	swap_nodes(stack_b);
	write(1, "sb\n", 3);
}

/**
 * sa and sb at the same time.
 */
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	write(1, "ss\n", 3);
}
