/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:29:21 by obensarj          #+#    #+#             */
/*   Updated: 2025/03/20 17:29:38 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate(t_stack *stack_x)
{
	int	i;
	int	*arr;

	if (stack_x->size <= 1)
		return ;
	arr = malloc(stack_x->size * sizeof(int));
	if (!arr)
		return ;
	i = -1;
	while (++i < stack_x->size - 1)
		arr[i] = stack_x->arr[i + 1];
	arr[i] = stack_x->arr[0];
	free(stack_x->arr);
	stack_x->arr = arr;
}

void	rev_r(t_stack *stack_x)
{
	int	i;
	int	*arr;

	if (stack_x->size <= 1)
		return ;
	arr = malloc(stack_x->size * sizeof(int));
	if (!arr)
		return ;
	arr[0] = stack_x->arr[stack_x->size - 1];
	i = 0;
	while (++i < stack_x->size)
		arr[i] = stack_x->arr[i - 1];
	free(stack_x->arr);
	stack_x->arr = arr;
}
