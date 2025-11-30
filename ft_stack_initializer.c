/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 18:00:22 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_stack_malloc_a(int number, char **arr_digit)
{
	t_stack	*a;
	int		i;
	int		index;
	int		how_many_equal;
	
	how_many_equal = 0;
	i = -1;
	index = 0;
	a = malloc(sizeof(t_stack));
	a->x = number;
	while (arr_digit[++i] != NULL)
	{
		if (number > ft_atoi(arr_digit[i]))
			index++;
		if (number == ft_atoi(arr_digit[i]))
			how_many_equal++;
	}
	if (how_many_equal != 1)
	{
		free(a);
		return(0);
	}
	a->index = index;
	a->next = NULL;
	return (a);
}

t_stack	*ft_stack_a(char const **av)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr_digit;
	int			how_many_digit;
	int			i;

	temp = NULL;
	head = NULL;
	i = 0;
	how_many_digit = 0;
	arr_digit = ft_av_converter(av);
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	while (i < how_many_digit)
	{
		head = ft_stack_malloc_a(ft_atoi(arr_digit[how_many_digit - 1]), arr_digit);
		if(!head)
			ft_error_return_stack(arr_digit, head);
		head->next = temp;
		temp = head;
		how_many_digit--;
	}
	ft_free(arr_digit);
	return (head);
}
