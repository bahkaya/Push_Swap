/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:49:46 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/23 18:54:03 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_msb_bit(int stack_size)
{
	int	how_many_bits;
	
	how_many_bits = 0;
	while ((stack_size - 1) >> how_many_bits)
		how_many_bits ++;
	return(how_many_bits);
}
void ft_radix_sort(t_stack **a, int how_many_bits, int stack_size, t_stack **b)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < how_many_bits)
	{
		j = stack_size;
		while (j > 0)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j--;
		}
		while ((*b) != NULL)
		{
			pa(a, b);
		}
		i++;
	}
}
