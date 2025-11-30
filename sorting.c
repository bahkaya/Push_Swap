/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:14:21 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 17:40:15 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ft_is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void ft_n_arg(char const **av, int ac, t_stack *a)
{
	t_stack	*b;
	int		how_many_bits;
	int		stack_size;

	b = NULL;
	stack_size = 0;
	how_many_bits = 0;
	a = ft_n_stack_a(av, ac);
	stack_size = ft_stack_size(a);
	how_many_bits = ft_msb_bit(stack_size);
	if (ft_is_sorted(a))
		return;
	ft_radix_sort(&a, how_many_bits, stack_size, &b);
}

void ft_one_arg(char const **av, t_stack *a)
{
	t_stack *b;
	int		how_many_bits;
	int		stack_size;

	b = NULL;
	how_many_bits = 0;
	stack_size = 0;
	how_many_bits = 0;
	a = ft_stack_a(av);
	if (ft_is_sorted(a))
		return;
	stack_size = ft_stack_size(a);
	how_many_bits = ft_msb_bit(stack_size);
	if (ft_is_sorted(a))
		return;
	ft_radix_sort(&a, how_many_bits, stack_size, &b);
}

void ft_sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;	
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void ft_before_radix(t_stack **a, t_stack **b, int stack_size)
{
	if (stack_size <= 1)
		return;
	if (stack_size == 2)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return;
	}
	if (stack_size == 3)
	{
		ft_sort_3(a);
		return;
	}

    // For 4–6 elements: push smallest elements to b
    while (ft_stack_size(*a) > 3)
    {
		t_stack *tmp = *a;
		int min_index = tmp->index;
		int min_pos = 0;
		int pos = 0;	
		// Find position of smallest element
		while (tmp)
		{
			if (tmp->index < min_index)
			{
				min_index = tmp->index;
				min_pos = pos;
			}
			tmp = tmp->next;
			pos++;
		}	
		// Rotate to bring smallest to top
		if (min_pos <= ft_stack_size(*a)/2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			min_pos = ft_stack_size(*a) - min_pos;
			while (min_pos-- > 0)
				rra(a);
		}	
		pb(a, b); // push smallest to b
	}

	// Sort remaining 3 in a
	ft_sort_3(a);

	// Push back from b to a
	while (*b)
		pa(a, b);
}
