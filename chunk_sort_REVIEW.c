/*
** ============================================================
** CHUNKED TARGET SELECTION - review only, not wired into Makefile
** ============================================================
**
** Idea: instead of letting push_best_to_b() chase the single
** globally-cheapest element across the WHOLE of stack_a every
** time, restrict candidates to a "chunk" of ranks at a time.
** This keeps stack_b roughly sorted in chunk-order, which makes
** phase 2 (push_best_to_a) much cheaper for large n.
**
** ---- struct change (push_swap.h, inside t_node) ----
** Add one field:
**     int  rank;
** (rank = position of this value among all n values, 0..n-1,
**  computed once at the start and never changed afterwards -
**  unlike ->index which is recomputed every iteration)
**
** ---- new field assignment ----
** Call assign_ranks(*stack_a) ONCE, immediately after the
** initial pb, pb in large_sort() (large_sort.c line 50-51),
** while stack_a+stack_b together still hold all n nodes.
*/

#include "push_swap.h"

void	assign_ranks(t_node *stack_a, t_node *stack_b)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = stack_a;
	while (i)
	{
		rank = 0;
		j = stack_a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		j = stack_b;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
	i = stack_b;
	while (i)
	{
		rank = 0;
		j = stack_a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		j = stack_b;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}

/*
** ---- replacement for the main push loop ----
**
** REMOVE from large_sort.c (lines 52-56):
**
**     while (get_stack_size(*stack_a) > 3)
**     {
**         cost_analysis_a(*stack_a, *stack_b);
**         push_best_to_b(stack_a, stack_b);
**     }
**
** REPLACE with a call to chunked_push_phase() below.
**
** chunk_lo/chunk_hi define the current "window" of ranks that
** are eligible to move to B right now. We grow the window by
** chunk_size each time the current window is exhausted (i.e.
** every node still in A has rank >= chunk_hi already, meaning
** none of the "due" elements are left).
**
** chunk_size = ceil(sqrt(n_to_move)) is the classic choice.
** n_to_move = (initial size_a) - 3, computed BEFORE the loop
** starts (i.e. right after assign_ranks, before any pb()s in
** this phase - remember 2 elements already went to B before
** this point via the existing pb,pb).
*/

static int	count_eligible(t_node *stack_a, int chunk_hi)
{
	int	n;

	n = 0;
	while (stack_a)
	{
		if (stack_a->rank < chunk_hi)
			n++;
		stack_a = stack_a->next;
	}
	return (n);
}

void	chunked_push_phase(t_node **stack_a, t_node **stack_b, int n_to_move)
{
	int	chunk_size;
	int	chunk_hi;

	chunk_size = 1;
	while (chunk_size * chunk_size < n_to_move)
		chunk_size++;
	chunk_hi = chunk_size;
	while (get_stack_size(*stack_a) > 3)
	{
		while (count_eligible(*stack_a, chunk_hi) == 0)
			chunk_hi += chunk_size;
		cost_analysis_a(*stack_a, *stack_b);
		/*
		** mask out (set push_cost = INT_MAX) every node in
		** stack_a whose rank >= chunk_hi, so get_min_cost_node()
		** can only pick from the current/earlier chunks.
		** This loop is the only NEW logic inside cost_analysis_a's
		** result - everything else in push_best_to_b is unchanged.
		*/
		{
			t_node	*tmp = *stack_a;
			while (tmp)
			{
				if (tmp->rank >= chunk_hi)
					tmp->push_cost = INT_MAX;
				tmp = tmp->next;
			}
		}
		push_best_to_b(stack_a, stack_b);
	}
}

/*
** ---- phase 2 (B -> A) ----
** Leave this phase as-is for a first pass. Because phase 1 now
** drains B in roughly ascending-rank chunk order, the existing
** greedy push_best_to_a should already see lower average cost
** without any change. If you still want >5% more after testing
** phase 1, the symmetric chunked_pop_phase() can be written the
** same way using set_target_b/cost_analysis_b, but try phase 1
** alone first and measure.
**
** ---- summary of integration steps ----
** 1. push_swap.h: add `int rank;` to t_node.
** 2. large_sort.c line 50-51 (after the two pb() calls):
**       assign_ranks(*stack_a, *stack_b);
**       n_to_move = get_stack_size(*stack_a) - 3;
** 3. large_sort.c lines 52-56: replace the while-loop with
**       chunked_push_phase(stack_a, stack_b, n_to_move);
** 4. Add this file (rename to chunk_sort.c) to Makefile SRCS,
**    and add its 2 prototypes to push_swap.h.
** 5. Re-test 100/500 averages; tune chunk_size formula
**    (try sqrt(n), sqrt(n)*1.5, n/8 etc.) if needed.
*/
