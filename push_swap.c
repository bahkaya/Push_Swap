/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/25 20:45:01 by bahkaya          ###   ########.fr       */
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
	print_stack2(a);
	free_stack(a);
	return 0;
}
// TODO: STACK B YAPILDI 2- ra ba pb yapılacak
// TODO: ft_stack içindeki freeler veya parselar değişmesi gerekiyor çünkü stack b için 
// malloc lzm
//TODO: Gerekli fonksiyonlar 
// Parserda eksiklikler var denenen caseleri öğrenip handle lamak lazım.
//ÖRn
/*
./push_swap 50 40 asda 
 % ./push_swap 50 40 32131
 artı eksi olmaması lazım. hata dönmeli
  % ./push_swap "50" 40 32131
  max int le ilgili caseler var.
*/

//TODO
// ra pa fln lar tamamlanıcak.
//TODO
/*
 A stackinde sayıların mevcut. B stacki oluşturulucak.
 Sayıların indexi buluncak lsb ye göre
*/

//TODO
//indexe göre a b stacklerini kullanarak sıralayacaksın.
// stack'e 5 ten az sayı gelirse özel bir case yazılacak.
//leakler bakılacak caseler denenicek.
//En son sıralamalar yapıldıktan sonra stackler freelenmesi lazım.


