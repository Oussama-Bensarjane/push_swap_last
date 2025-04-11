/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:20:12 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/10 23:58:00 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_handle_lmax(unsigned long nbr, int sign, int count)
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

int	ft_atoi(char *str, char **args, int *arr)
{
	long	nbr;
	int		sign;
	int		count;

	nbr = 0;
	sign = 1;
	count = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			nbr = (nbr * 10) + (*str++ - '0');
		if (nbr != 0 && !count)
			count = 1;
		if (count && ft_handle_lmax(nbr, sign, count++) != 1)
			(free(arr), free_f(args), print_error(), exit(1));
		if (*str < '0' && *str > '9')
			(free(arr), free_f(args), print_error(), exit(1));
	}
	if ((nbr * sign) > INT_MAX || (nbr * sign) < INT_MIN)
		(free(arr), free_f(args), print_error(), exit(1));
	return (nbr * sign);
}
