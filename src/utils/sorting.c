/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:31:42 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/11 19:47:21 by obensarj         ###   ########.fr       */
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
		if (a->arr[i] - a->arr[i - 1] < 4)
			counter++;
		i++;
	}
	if ((counter * 100 / a->size) >= 60)
		return (0);
	return (-1);
}

// void	push_chunks_to_b(t_stack *a, t_stack *b, int *sorted_copy, int chunk_size)
// {
// 	int	i;
// 	int	sc;
// 	int	size;

// 	i = 0;
// 	sc = should_reverse_rotate(a);
// 	size = a->size;
// 	bubble_sort(sorted_copy, a->arr, a->size);
// 	while (a->size != 0)
// 	{
// 		if (get_index(a->arr[0], sorted_copy, size) <= i)
// 			(move("pb", a, b), i++);
// 		else if (get_index(a->arr[0], sorted_copy, size) <= i + chunk_size)
// 			(move("pb", a, b), move("rb", NULL, b), i++);
// 		else
// 		{
// 			if (sc == -1)
// 				move("ra", a, b);
// 			else
// 				move("rra", a, NULL);
// 		}
// 	}
// }
void	push_chunks_to_b(t_stack *a, t_stack *b, int *sorted_copy, int chunk_size)
{
	int	i = 0;
	int	size = a->size;

	bubble_sort(sorted_copy, a->arr, size);

	while (a->size > 0)
	{
		int j = 0;
		int element_index_in_sorted = -1;
		int element_pos = -1;

		// Find the position of the first element in the current chunk
		while (j < a->size)
		{
			int idx = get_index(a->arr[j], sorted_copy, size);
			if (idx <= i + chunk_size)
			{
				element_index_in_sorted = idx;
				element_pos = j;
				break;
			}
			j++;
		}

		if (element_pos == -1)
		{
			i += chunk_size; // no element in current chunk? move to next chunk
			continue;
		}

		// Bring the element to top using optimal rotations
		if (element_pos <= a->size / 2)
			while (element_pos-- > 0)
				move("ra", a, b);
		else
			while (element_pos++ < a->size)
				move("rra", a, b);

		// Push and rotate B if needed
		if (element_index_in_sorted <= i)
		{
			move("pb", a, b);
			i++;
		}
		else
		{
			move("pb", a, b);
			move("rb", NULL, b);
			i++;
		}
	}
}


void	move_a_to_b_in_chunks(t_stack *a, t_stack *b)
{
	int	*sorted_copy;
	int	chunk_size;

	sorted_copy = (int *)malloc(a->size * sizeof(int));
	if (!sorted_copy)
		return ;
	if (a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	push_chunks_to_b(a, b, sorted_copy, chunk_size);
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
