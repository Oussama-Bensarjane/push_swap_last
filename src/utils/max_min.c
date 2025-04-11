/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:27:17 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/11 19:44:23 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	max_n(t_stack *a)
{
	int	i;
	int	max;

	if (!a || a->size == 0)
		return (0);
	i = -1;
	max = a->arr[0];
	while (++i < a->size)
	{
		if (max < a->arr[i])
			max = a->arr[i];
	}
	return (max);
}

int	min_n(t_stack *a)
{
	int	i;
	int	min;

	if (!a || a->size == 0)
		return (0);
	i = -1;
	min = a->arr[0];
	while (++i < a->size)
	{
		if (min > a->arr[i])
			min = a->arr[i];
	}
	return (min);
}

int	get_index(int a_el, int *sorted_copy, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (sorted_copy[i] == a_el)
			return (i);
	}
	return (-1);
}
