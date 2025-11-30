/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 17:50:45 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *a)
{
	t_stack *tmp;

	while (a != NULL)
	{
		tmp = a->next;
		free (a);
		a = tmp;
	}
}

void print_stack(t_stack *a)
{
	t_stack *print_stack;
	print_stack = a;
	while (print_stack != NULL)
	{
			printf("sa %d\n", print_stack->x);
				print_stack = print_stack->next;
	}
}
void print_stack2(t_stack *a)
{
	t_stack *print_stack;
	print_stack = a;
	while (print_stack != NULL)
	{
			printf("%d\n", print_stack->x);
				print_stack = print_stack->next;
	}
}

int main(int ac, char const **av)
{
	if (ac <= 1)
	{
		write(2, "Error\n", 6);
		exit (-1);
	}
	t_stack	*a;
	if (ac == 2)
	{
		a = NULL;
		ft_one_arg(av, a);
	}
	if (ac > 2)
	{
		a = NULL;
		ft_n_arg(av, ac, a);
	}
	free_stack(a);
	return 0;
}
