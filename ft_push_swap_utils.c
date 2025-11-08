/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:46:19 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/08 20:41:05 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}
void sa(t_stack **a)
{
	t_stack *first;
	t_stack *second;
	first = *a;
	second = (*a)->next;
	int value_temp;
	value_temp = 0;
	value_temp = first->x;
	first->x = second->x;
	second->x = value_temp;
}
void sb(t_stack **b)
{
	t_stack *first;
	t_stack *second;
	int value_temp;

	first = *b;
	second = (*b)->next;
	value_temp = 0;
	value_temp = first->x;
	first->x = second->x;
	second->x = value_temp;
}


void ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
// Take the first element at the top of b and put it at the top of a
void pa(t_stack **a, t_stack **b)
{
	t_stack	*first_b;
	t_stack *first_a;

	first_b = *b;
	first_a = *a;
	(*b) = (*b)->next; 
	first_b->next = (*a);
	(*a) = first_b;
}
// Take the first element at the top of a and put it at the top of b
void pb(t_stack **a, t_stack **b)
{
	t_stack *first_a;
	t_stack *first_b;
	
	first_a = *a;
	first_b = *b;
	(*a) = (*a) ->next;
	first_a->next = (*b);
	(*b) = first_a;
}
void ra(t_stack **a)
{
	t_stack *last;
	t_stack *temp;

	temp = *a;
	last = *a;
	while (last->next != NULL)
	{
		if(last->next == NULL)
			break;
		last = last->next;
	}
	while (temp->next != NULL)
	{
		if(temp->next == last)
		{
			break;
		}
		temp = temp->next;
	}
	temp->next = NULL;
	last->next = *a;
	*a = last;
}
