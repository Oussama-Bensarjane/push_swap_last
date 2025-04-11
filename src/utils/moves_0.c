/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:28:33 by obensarj          #+#    #+#             */
/*   Updated: 2025/03/20 17:28:58 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move(char *move, t_stack *stack_a, t_stack *stack_b)
{
	if (!move)
		return ;
	if (ft_strcmp(move, "sa") == 0)
		(swap(stack_a), write(1, "sa\n", 3));
	else if (ft_strcmp(move, "sb") == 0)
		(swap(stack_b), write(1, "sb\n", 3));
	else if (ft_strcmp(move, "ss") == 0)
		(swap(stack_a), swap(stack_b), write(1, "ss\n", 3));
	else if (ft_strcmp(move, "pa") == 0)
		(pa(stack_a, stack_b), write(1, "pa\n", 3));
	else if (ft_strcmp(move, "pb") == 0)
		(pb(stack_a, stack_b), write(1, "pb\n", 3));
	else if (ft_strcmp(move, "ra") == 0)
		(rotate(stack_a), write(1, "ra\n", 3));
	else if (ft_strcmp(move, "rb") == 0)
		(rotate(stack_b), write(1, "rb\n", 3));
	else if (ft_strcmp(move, "rr") == 0)
		(rotate(stack_a), rotate(stack_b), write(1, "rr\n", 3));
	else if (ft_strcmp(move, "rra") == 0)
		(rev_r(stack_a), write(1, "rra\n", 4));
	else if (ft_strcmp(move, "rrb") == 0)
		(rev_r(stack_b), write(1, "rrb\n", 4));
	else if (ft_strcmp(move, "rrr") == 0)
		(rev_r(stack_a), rev_r(stack_b), write(1, "rrr\n", 4));
}

void	swap(t_stack *stack_x)
{
	int	tmp;

	if (stack_x->size <= 1)
		return ;
	tmp = stack_x->arr[0];
	stack_x->arr[0] = stack_x->arr[1];
	stack_x->arr[1] = tmp;
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*arr;
	int	*arr2;

	if (stack_b->size == 0)
		return ;
	arr = malloc((stack_a->size + 1) * sizeof(int));
	arr2 = malloc((stack_b->size - 1) * sizeof(int));
	if (!arr || !arr2)
		return ;
	arr[0] = stack_b->arr[0];
	i = -1;
	while (++i < stack_a->size)
		arr[i + 1] = stack_a->arr[i];
	i = -1;
	while (++i < stack_b->size - 1)
		arr2[i] = stack_b->arr[i + 1];
	free(stack_a->arr);
	stack_a->arr = arr;
	stack_a->size += 1;
	free(stack_b->arr);
	stack_b->arr = arr2;
	stack_b->size -= 1;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*arr;
	int	*arr2;

	if (stack_a->size == 0)
		return ;
	arr = malloc((stack_b->size + 1) * sizeof(int));
	arr2 = malloc((stack_a->size - 1) * sizeof(int));
	if (!arr || !arr2)
		return ;
	arr[0] = stack_a->arr[0];
	i = -1;
	while (++i < stack_b->size)
		arr[i + 1] = stack_b->arr[i];
	i = -1;
	while (++i < stack_a->size - 1)
		arr2[i] = stack_a->arr[i + 1];
	free(stack_b->arr);
	stack_b->arr = arr;
	stack_b->size += 1;
	free(stack_a->arr);
	stack_a->arr = arr2;
	stack_a->size -= 1;
}
