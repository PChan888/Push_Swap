/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 22:09:57 by kaichan           #+#    #+#             */
/*   Updated: 2025/09/26 01:24:47 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in the list
int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		++counter;
		lst = lst->next;
	}
	return (counter);
}

// #include <stdio.h> // print
// #include <stdlib.h> // free
//
// int main(void)
// {
//     t_list *list = NULL;
//
//     // Create 5 nodes
//     ft_lstadd_back(&list, ft_lstnew("Node 1"));
//     ft_lstadd_back(&list, ft_lstnew("Node 2"));
//     ft_lstadd_back(&list, ft_lstnew("Node 3"));
//     ft_lstadd_back(&list, ft_lstnew("Node 4"));
//     ft_lstadd_back(&list, ft_lstnew("Node 5"));
//
//     // Test ft_lstsize
//     printf("List size: %d\n", ft_lstsize(list)); // Should print 5
//
//     return 0;
// }