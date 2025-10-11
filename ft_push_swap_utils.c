/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:46:19 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/11 17:44:09 by bahkaya          ###   ########.fr       */
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