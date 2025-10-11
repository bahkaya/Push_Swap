/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/11 17:38:42 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			printf("ra %d\n", print_stack->x);
				print_stack = print_stack->next;
	}
}

int main(int ac, char const **av)
{
	if (ac == 2)
	{
		int		number;
		t_stack	*a;
		a = ft_stack(av, ac);
		number = 0;
		number = ft_stack_size(a);
		printf("stack size --%d\n", number);
		sa(&a);
		print_stack(a);
		ra(&a);
		print_stack2(a);
	}
		return 0;
}
