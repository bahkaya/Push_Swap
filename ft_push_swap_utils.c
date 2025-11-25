/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:46:19 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/23 21:42:11 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a->next != NULL)
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
	int value_temp;
	if (!a || !*a || !(*a)->next)
		return;
	first = *a;
	second = (*a)->next;
	value_temp = 0;
	value_temp = first->x;
	first->x = second->x;
	second->x = value_temp;
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}


void ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
// Take the first element at the top of b and put it at the top of a
void pa(t_stack **a, t_stack **b)
{
	t_stack	*first_b;

	if (!b || !*b)
		return;
	first_b = *b;
	(*b) = (*b)->next; 
	first_b->next = (*a);
	(*a) = first_b;
	write(1, "pa\n", 3);
}
// Take the first element at the top of a and put it at the top of b
void pb(t_stack **a, t_stack **b)
{
	t_stack *first_a;

	if (!b || !*b)
		return;
	first_a = *a;
	(*a) = (*a) ->next;
	first_a->next = (*b);
	(*b) = first_a;
	write(1, "pb\n", 3);
}
void rra(t_stack **a)
{
	t_stack *last;
	t_stack *temp;

	if (!a || !*a || !(*a)->next)
		return;
	temp = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
void rrb(t_stack **b)
{
	t_stack *last;
	t_stack *temp;
	
	if (!b || !*b || !(*b)->next)
		return;
	temp = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;

	while (temp->next != last)
		temp = temp->next;

	temp->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}
void rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}
void ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;
	
	if (!a || !*a || !(*a)->next)
		return;
	first = *a;
	last = *a;
	while (last->next != NULL)
	last = last->next;
	
	*(a) = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
	t_stack *first;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return;
	first = *b;
	last = *b;
	while (last->next != NULL)
	last = last->next;
	
	*(b) = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}
void rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}