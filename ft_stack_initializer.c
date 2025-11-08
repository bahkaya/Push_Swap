/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/08 19:37:07 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_stack_malloc_a(int number)
{
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->x = number;
	a->next = NULL;
	return (a);
}
t_stack	*ft_stack_malloc_b(char const **av)
{
	t_stack	*temp;
	t_stack	*head;
	char	**arr_digit;
	int		flag;
	int		how_many_digit;
	int		i;

	how_many_digit = 0;
	i = 0;
	temp = NULL;
	arr_digit = ft_av_converter(av, &flag);
	if (flag == 5)
	{
		ft_free(arr_digit);
		exit (-1);
	}
	
	if (!arr_digit)
	{
		write(1, "ERROR\n", ft_strlen("ERROR\n"));
		ft_free(arr_digit);
		exit(-1);
	}
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	while (i < how_many_digit)
	{
		head = malloc(sizeof(t_stack));
		head->next = temp;
		temp = head;
		i++;
	}
	ft_free(arr_digit);
	return (head);
}
//TODO Stack boş oluşması lazım sonradan içerisine sayı atılacak. Return sıkıntısı.
t_stack	*ft_stack_a(char const **av, int ac)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr_digit;
	int			how_many_digit;
	int			i;
	int flag;

	flag = 0;
	if (ac == 31)
		printf("%s\n", "OSMAN ABUBAKAR");
	temp = NULL;
	i = 0;
	how_many_digit = 0;
	arr_digit = ft_av_converter(av, &flag);
	if (flag == 5)
	{
		ft_free(arr_digit);
		exit (-1);
	}
	
	if (!arr_digit)
	{
		write(1, "ERROR\n", ft_strlen("ERROR\n"));
		ft_free(arr_digit);
		exit(-1);
	}
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	while (i < how_many_digit)
	{
		head = ft_stack_malloc_a(ft_atoi(arr_digit[i]));
		head->next = temp;
		temp = head;
		i++;
	}
	ft_free(arr_digit);
	return (head);
}

/*
head
----
201 55
null


if ()
*/