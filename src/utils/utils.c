/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:32:10 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/11 19:44:23 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd(RED_COLOR"Error\n"END_COLOR, 2);
}

void	free_f(char **arr)
{
	int	i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
		free(arr);
	}
}

int	is_sorted(t_stack *stack_x)
{
	int	i;

	i = 0;
	while (i < stack_x->size - 1)
	{
		if (stack_x->arr[i] > stack_x->arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	get_max(t_stack *b, int *max)
{
	int	i;
	int	position;

	i = -1;
	position = 0;
	*max = b->arr[0];
	while (++i < b->size)
	{
		if (b->arr[i] > *max)
		{
			*max = b->arr[i];
			position = i;
		}
	}
	return (position);
}

void	bubble_sort(int *sorted_copy, int *original, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
		sorted_copy[i] = original[i];
	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_copy[i] > sorted_copy[j])
			{
				tmp = sorted_copy[i];
				sorted_copy[i] = sorted_copy[j];
				sorted_copy[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
