/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:47:23 by kai               #+#    #+#             */
/*   Updated: 2026/06/13 01:01:17 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Safely swaps the first two nodes of a doubly linked list.
 * * Wireframe changes handled:
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
 * @brief Swaps the first 2 elements at the top of stack a.
 */
void	sa(t_node **stack_a, int print_flag)
{
	swap_nodes(stack_a);
	if (print_flag)
		write(1, "sa\n", 3);
}

/**
 * @brief Swaps the first 2 elements at the top of stack b.
 */
void	sb(t_node **stack_b, int print_flag)
{
	swap_nodes(stack_b);
	if (print_flag)
		write(1, "sb\n", 3);
}

/**
 * @brief sa and sb at the same time.
 */
void	ss(t_node **stack_a, t_node **stack_b, int print_flag)
{
	swap_nodes(stack_a);
	swap_nodes(stack_b);
	if (print_flag)
		write(1, "ss\n", 3);
}
