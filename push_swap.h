/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 21:22:08 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/11 17:38:23 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
typedef struct s_stack
{
	int	x;
	struct s_stack *next;
} t_stack;

char **ft_av_converter(char const **av);
t_stack	*ft_stack_malloc(int number);
t_stack	*ft_stack(char const **av, int ac);
int	ft_stack_size(t_stack *a);
void sa(t_stack **a);
void ra(t_stack **a);