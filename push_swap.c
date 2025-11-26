/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/26 22:08:58 by bahkaya          ###   ########.fr       */
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
			printf(" %d\n", print_stack->x);
				print_stack = print_stack->next;
	}
}

int main(int ac, char const **av)
{
	int		stack_size;
	int		how_many_bits;
	

	if (ac <= 1)
	{
		write(2, "Error\n", 6);
		exit (-1);
	}
		
	t_stack	*a;
	t_stack *b;
	
	if (ac == 2)
	{
		b = NULL;
		how_many_bits = 0;
		a = ft_stack_a(av);
		stack_size = ft_stack_size(a);
		how_many_bits = ft_msb_bit(stack_size);
		ft_radix_sort(&a, how_many_bits, stack_size, &b);
	}
	if (ac > 2)
	{
		b = NULL;
		how_many_bits = 0;
		a = ft_n_stack_a(av, ac);
		stack_size = ft_stack_size(a);
		how_many_bits = ft_msb_bit(stack_size);
		ft_radix_sort(&a, how_many_bits, stack_size, &b);
	}
	
	free_stack(a);
	return 0;
}
//TODO
//1-ft_atoinde hata var dikkat et onu kontrol et int max int min almıyor
//2-ft_free birden fazla argümanda hata var
//3-12 tane sayı olursa bunları düzelt 
//4- Sonradan radixine bak
//5- norm düzelt
//6- ./a.out ise return(0) yaz

