/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obensarj <obensarj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:13:26 by obensarj          #+#    #+#             */
/*   Updated: 2025/04/11 19:44:23 by obensarj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define RED_COLOR "\033[31m"
# define END_COLOR "\033[0m"

typedef struct s_stack {
	int	*arr;
	int	size;
}				t_stack;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_atoi(char *str, char **args, int *arr);
int		ft_handle_lmax(unsigned long nbr, int sign, int count);
int		is_sorted(t_stack *stack_x);
void	print_error(void);
void	free_f(char **arr);
void	parser(int ac, char **av, t_stack *stack_a);
int		*check_nums(char **args, int size);
void	move(char *move, t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack_x);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack_x);
void	rev_r(t_stack *stack_x);
void	sort(t_stack *a, t_stack *b);
void	sorting(t_stack *a, t_stack *b);
int		max_n(t_stack *a);
int		min_n(t_stack *a);
int		get_max(t_stack *b, int *max);
void	bubble_sort(int *sorted_copy, int *original, int size);
int		get_index(int a_el, int *sorted_copy, int size);
void	*ft_memset(void *b, int c, size_t len);
void	empty_check(int ac, char **av);
void	plus_minus_check(int ac, char **av);
void	invalid_char(int ac, char **av);
int		*stoi(char **args);
void	dup_check(int *arr, int end);

#endif