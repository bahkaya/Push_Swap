/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:22:08 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/08 19:59:03 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
typedef struct s_stack
{
	int	x;
	int	index;
	struct s_stack *next;
} t_stack;

char **ft_av_converter(char const **av, int *flag);
t_stack	*ft_stack_malloc_a(int number);
t_stack	*ft_stack_a(char const **av, int ac);
t_stack	*ft_stack_malloc_b(char const **av);
int	ft_stack_size(t_stack *a);
void sa(t_stack **a);
void ra(t_stack **a);
void pa(t_stack **a, t_stack **b);

void	ft_free(char **str_is_digit);