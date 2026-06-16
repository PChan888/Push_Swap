/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kai <kai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:10:53 by kai               #+#    #+#             */
/*   Updated: 2026/06/17 02:05:15 by kai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Just creates a new node.
t_node	*lst_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->push_cost = INT_MAX;
	new_node->above_mid = 0;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// Adds a new node to the end of the stack. 
void	lst_add_back(t_node **stack, t_node *new_node)
{
	t_node	*tail;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new_node;
	new_node->prev = tail;
}

// Safely cleans up and frees all nodes in linked list
void	free_stack(t_node **stack)
{
	t_node	*cur;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	cur = *stack;
	while (cur)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	*stack = NULL;
}
