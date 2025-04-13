/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:20:12 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/12 21:15:18 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	lmax_handler(unsigned long nbr, int sign, int count)
{
	if (nbr > 9223372036854775807 || count >= 20)
	{
		if (sign == 1)
			return (-1);
		else if (sign == -1)
			return (0);
	}
	return (1);
}

void	init_parse_data(t_parse_data *data)
{
	data->nbr = 0;
	data->sign = 1;
	data->count = 0;
}

int	ft_atoi(char *str, char **args, int *arr)
{
	t_parse_data	data;

	init_parse_data(&data);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			data.sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			data.nbr = (data.nbr * 10) + (*str++ - '0');
		if (data.nbr != 0 && !data.count)
			data.count = 1;
		if (data.count && lmax_handler(data.nbr, data.sign, data.count++) != 1)
			(free(arr), free_f(args), print_error(), exit(1));
		if (*str < '0' && *str > '9')
			(free(arr), free_f(args), print_error(), exit(1));
	}
	if ((data.nbr * data.sign) > INT_MAX || (data.nbr * data.sign) < INT_MIN)
		(free(arr), free_f(args), print_error(), exit(1));
	return (data.nbr * data.sign);
}
