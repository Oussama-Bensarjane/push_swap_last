/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:17:02 by obensarj          #+#    #+#             */
/*   Updated: 2025/03/25 23:12:03 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	hel;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_b.arr = NULL;
	stack_b.size = 0;
	parser(ac, av, &stack_a);
	sort(&stack_a, &stack_b);
	free(stack_a.arr);
}
