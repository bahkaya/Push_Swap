/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:22:08 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 18:30:49 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct s_stack
{
	int				x;
	int				index;
	struct s_stack	*next;
}	t_stack;

char	**ft_av_converter(char const **av);
char	**ft_n_av_converter(char const **av, int ac);
void	ft_check_for_max(char **arr_is_digit);
void	ft_error_check_n_argv(char const **av);
void	ft_error_return_stack(char **arr_digit, t_stack *head);
void	ft_error_return_pointer(char **arr_digit);
int		ft_msb_bit(int stack_size);
void	ft_n_arg(char const **av, int ac, t_stack *a);
void	ft_one_arg(char const **av, t_stack *a);
void	ft_before_radix(t_stack **a, t_stack **b, int stack_size);
t_stack	*ft_stack_malloc_a(int number, char **av);
t_stack	*ft_stack_a(char const **av);
t_stack	*ft_n_stack_a(char const **av, int ac);
void	ft_radix_sort(t_stack **a, int how_many, int stack, t_stack **b);
int		ft_stack_size(t_stack *a);
void	sa(t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
int		ft_is_sorted(t_stack *a);
void	print_stack2(t_stack *a);
void	free_stack(t_stack *a);
void	ft_free(char **str_is_digit);
#endif