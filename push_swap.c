/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:53:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/08 20:52:02 by bahkaya          ###   ########.fr       */
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
	int		number;
	
	if (ac < 1)
		exit(-1);
		
	t_stack	*a;
	t_stack	*b;

	b= NULL;
	a = ft_stack_a(av, ac);
	b = ft_stack_malloc_b(av);
	number = 0;
	number = ft_stack_size(a);
	printf("stack size --%d\n", number);
	b->x = 31;
	pa(&a, &b);
	while(a != NULL)
	{
		printf("%d\n", a->x);
		a = a-> next;
	}
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


