/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 20:49:29 by kai               #+#    #+#             */
/*   Updated: 2026/06/10 20:49:35 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pops the top node from src and pushes it to the top of dest.
 */
static void	push_node(t_node **dest, t_node **src)
{
	t_node	*node_to_move;

	if (!src || !*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_move;
	*dest = node_to_move;
}

void	pa(t_node **stack_a, t_node **stack_b, int print_flag)
{
	push_node(stack_a, stack_b);
	if (print_flag)
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, int print_flag)
{
	push_node(stack_b, stack_a);
	if (print_flag)
		write(1, "pb\n", 3);
}