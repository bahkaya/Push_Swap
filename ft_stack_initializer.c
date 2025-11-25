/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/25 21:00:09 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_stack_malloc_a(int number, char **arr_digit)
{
	t_stack	*a;
	int		i;
	int		index;
	int		how_many;
	
	how_many = 0;
	i = 0;
	index = 0;
	a = malloc(sizeof(t_stack));
	a->x = number;
	while (arr_digit[i] != NULL)
	{
		if (number > ft_atoi(arr_digit[i]))
			index++;
		if (number == ft_atoi(arr_digit[i]))
			how_many++;
		i++;
	}
	if (how_many != 1 || (how_many == 1 && i == 1)) // Burada birde stacki freelemek lzm sonra bakarsın
	{
		write(2, "Error\n", ft_strlen("Error\n")); // aşağıda bunu yapmışız 1 elemanlı stack ise o yüzden sorun yok ama eşit olabilme olasılığı var
		free_stack(a);
		exit(-1);
	}
	a->index = index;
	a->next = NULL;
	return (a);
}

char **ft_error_check(char **arr_digit, int *flag)
{
	if (*flag == 5)
	{
		ft_free(arr_digit);
		exit (-1);
	}
	if (!arr_digit)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		ft_free(arr_digit);
		exit(-1);
	}
	return (arr_digit);
}
//TODO Stack boş oluşması lazım sonradan içerisine sayı atılacak. Return sıkıntısı.
t_stack	*ft_stack_a(char const **av)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr_digit;
	int			how_many_digit;
	int			i;
	int flag;

	flag = 0;
	temp = NULL;
	i = 0;
	how_many_digit = 0;
	arr_digit = ft_av_converter(av, &flag);
	arr_digit = ft_error_check(arr_digit, &flag);
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	if (how_many_digit == 1)
	{
		write(2, "Error\n", 6);
		ft_free(arr_digit);
		exit (-1);
	}
	while (i < how_many_digit)
	{
		if (ft_atoi(arr_digit[how_many_digit - 1]) > __INT_MAX__ || ft_atoi(arr_digit[how_many_digit -1]) < _SC_INT_MIN)
		{
			write(2, "Error\n", 6);
			ft_free(arr_digit);
			free_stack(head);
			exit(-1);
		}
		head = ft_stack_malloc_a(ft_atoi(arr_digit[how_many_digit - 1]), arr_digit);
		if(!head)
		{
			write(2, "Error\n", 6);
			ft_free(arr_digit);
			free_stack(head);
			exit(-1);
		}
		head->next = temp;
		temp = head;
		how_many_digit--;
	}
	ft_free(arr_digit);
	return (head);
}
