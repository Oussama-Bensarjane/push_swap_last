/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:30:38 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/12 22:18:07 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	parser_2(char *arr, t_stack *a)
{
	int		i;
	int		*tab;
	char	**args;

	i = 0;
	tab = NULL;
	args = NULL;
	args = ft_split(arr, ' ');
	if (!args)
		return ;
	tab = stoi(args);
	i = 0;
	while (args[i])
		i++;
	free_f(args);
	dup_check(tab, i);
	a->arr = tab;
	a->size = i;
}

void	parser(int ac, char **av, t_stack *a)
{
	int		i;
	char	arr[10000];

	if (ac == 1)
		exit(0);
	i = 1;
	ft_memset(arr, 0, sizeof(arr));
	plus_minus_check(ac, av);
	invalid_char(ac, av);
	while (av[i])
	{
		ft_strlcat(arr, av[i], sizeof(arr));
		i++;
		if (av[i])
			ft_strlcat(arr, " ", sizeof(arr));
	}
	parser_2(arr, a);
}
