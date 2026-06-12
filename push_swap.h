/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaichan <kaichan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 04:21:26 by kaichan           #+#    #+#             */
/*   Updated: 2026/06/13 01:00:27 by kaichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* parser_input.c */
char	**input_split_and_flatten(int argc, char **argv);
int		check_array_and_dup(char **flat_array);
t_node	*build_doubly_stack(char **flat_array);

/* parser_utils.c */
int		get_flatten_count(int argc, char **argv);
void	mixed_fill(char **flat_array, char **argv, int argc);
int		is_valid_int(const char *str);
void	free_flat_array(char **flat_array);

/* list_utils.c */
t_node	*lst_new(int value);
void	lst_add_back(t_node **stack, t_node *new_node);
void	free_stack(t_node **stack);

/* error_exit.c */
void	error_exit(void);

/* sort_utils.c */
int		get_stack_size(t_node *stack);
int		is_sorted(t_node *stack);

/* op_push.c */
void	pa(t_node **stack_a, t_node **stack_b, int print_flag);
void	pb(t_node **stack_a, t_node **stack_b, int print_flag);

/* op_swap.c */
void	sa(t_node **stack_a, int print_flag);
void	sb(t_node **stack_b, int print_flag);
void	ss(t_node **stack_a, t_node **stack_b, int print_flag);

/* op_rotate.c */
void	ra(t_node **stack_a, int print_flag);
void	rb(t_node **stack_b, int print_flag);
void	rr(t_node **stack_a, t_node **stack_b, int print_flag);

/* op_rev_rotate.c */
void	rra(t_node **stack_a, int print_flag);
void	rrb(t_node **stack_b, int print_flag);
void	rrr(t_node **stack_a, t_node **stack_b, int print_flag);

/* sort_algorithms.c */
void	sort_stack(t_node **stack_a, t_node **stack_b);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);

/* large_sort.c */
void	large_sort(t_node **stack_a, t_node **stack_b);
void	finalize_rotation(t_node **stack_a);

/* turk_utils.c */
void	current_index(t_node *stack);
void	cost_analysis_a(t_node *stack_a, t_node *stack_b);
t_node	*find_max(t_node *stack);

/* turk_b_utils.c */
void	cost_analysis_b(t_node *stack_a, t_node *stack_b);
void	find_min(t_node *stack_a, int *min_val, int *min_pos);
t_node	*get_min_cost_node(t_node *stack);

/* turk_exec.c */
void	push_best_to_b(t_node **stack_a, t_node **stack_b);
void	push_best_to_a(t_node **stack_a, t_node **stack_b);

#endif
