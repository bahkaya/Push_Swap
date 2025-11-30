/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 18:23:40 by bahkaya          ###   ########.fr       */
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
		return (0);
	}
	a->index = index;
	a->next = NULL;
	return (a);
}

t_stack	*ft_stack_a(char const **av)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr;
	int			how_many;
	int			i;

	temp = NULL;
	head = NULL;
	i = 0;
	how_many = 0;
	arr = ft_av_converter(av);
	while (arr[how_many] != NULL)
		how_many++;
	while (i < how_many)
	{
		head = ft_stack_malloc_a(ft_atoi(arr[how_many - 1]), arr);
		if (!head)
			ft_error_return_stack(arr, head);
		head->next = temp;
		temp = head;
		how_many--;
	}
	ft_free(arr);
	return (head);
}
