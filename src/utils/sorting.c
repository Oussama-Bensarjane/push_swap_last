/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:31:42 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/12 17:55:25 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	should_reverse_rotate(t_stack *a)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] - a->arr[i - 1] > 1 && a->arr[i] - a->arr[i - 1] < 4)
			counter++;
		i++;
	}
	if ((counter * 100 / a->size) >= 60)
		return (1);
	return (0);
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int *sort_copy, int ch)
{
	int	i;
	int	sc;
	int	size;

	i = 0;
	sc = should_reverse_rotate(a);
	size = a->size;
	bubble_sort(sort_copy, a->arr, a->size);
	while (a->size != 0)
	{
		if (get_index(a->arr[0], sort_copy, size) <= i)
			(move("pb", a, b), i++);
		else if (get_index(a->arr[0], sort_copy, size) <= i + ch)
			(move("pb", a, b), move("rb", NULL, b), i++);
		else
		{
			if (!sc)
				move("ra", a, NULL);
			else
				move("rra", a, NULL);
		}
	}
}

void	move_a_to_b_in_chunks(t_stack *a, t_stack *b)
{
	int	*sorted_copy;
	int	ch;

	sorted_copy = malloc(a->size * sizeof(int));
	if (!sorted_copy)
		return ;
	if (a->size <= 100)
		ch = 16;
	else
		ch = 36;
	push_chunks_to_b(a, b, sorted_copy, ch);
	free(sorted_copy);
}

void	restore_sorted_from_b(t_stack *a, t_stack *b)
{
	int	max;
	int	element_pos;

	while (b->size > 1)
	{
		element_pos = get_max(b, &max);
		if (element_pos <= b->size / 2)
		{
			while (b->arr[0] != max)
				move("rb", NULL, b);
			move("pa", a, b);
		}
		else if (element_pos > b->size / 2)
		{
			while (b->arr[0] != max)
				move("rrb", NULL, b);
			move("pa", a, b);
		}
	}
	move("pa", a, b);
}

void	sorting(t_stack *a, t_stack*b)
{
	if (!a)
		return ;
	move_a_to_b_in_chunks(a, b);
	restore_sorted_from_b(a, b);
}
