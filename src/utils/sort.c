/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:31:04 by obensarj          #+#    #+#             */
/*   Updated: 2025/03/20 17:31:16 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack *a)
{
	if (a->arr[0] == max_n(a))
	{
		move("ra", a, NULL);
		if (is_sorted(a) != 0)
			move("sa", a, NULL);
	}
	else if (a->arr[1] == max_n(a))
	{
		move("rra", a, NULL);
		if (is_sorted(a) != 0)
			move("sa", a, NULL);
	}
	else if (a->arr[2] == max_n(a))
	{
		if (is_sorted(a) != 0)
			move("sa", a, NULL);
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	if (a->arr[0] == min_n(a))
		move("pb", a, b);
	else if (a->arr[1] == min_n(a))
	{
		move("sa", a, NULL);
		move("pb", a, b);
	}
	else if (a->arr[2] == min_n(a))
	{
		move("rra", a, NULL);
		move("rra", a, NULL);
		move("pb", a, b);
	}
	else if (a->arr[3] == min_n(a))
	{
		move("rra", a, NULL);
		move("pb", a, b);
	}
	sort_3(a);
	move("pa", a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	if (a->arr[0] == min_n(a))
		(move("pb", a, b), sort_4(a, b));
	else if (a->arr[1] == min_n(a))
		(move("sa", a, b), move("pb", a, b), sort_4(a, b));
	else if (a->arr[2] == min_n(a))
	{
		(move("ra", a, b), move("ra", a, b), move("pb", a, b));
		sort_4(a, b);
	}
	else if (a->arr[3] == min_n(a))
	{
		(move("rra", a, b), move("rra", a, b), move("pb", a, b));
		sort_4(a, b);
	}
	else if (a->arr[4] == min_n(a))
	{
		(move("rra", a, b), move("pb", a, b), sort_4(a, b));
	}
	move("pa", a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1)
		return ;
	if (is_sorted(a) == 0 && b->size == 0)
		return ;
	if (a->size == 2)
		move("sa", a, b);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else if (a->size > 5)
		sorting(a, b);
	if (b->arr)
		free(b->arr);
	return ;
}
