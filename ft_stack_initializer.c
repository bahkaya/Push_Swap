/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/10 22:01:43 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack	*ft_stack_malloc(int number)
{
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->x = number;
	a->next = NULL;
	return (a);
}

void	ft_stack(char const **av, int ac)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr_digit;
	int			how_many_digit;
	int			i;
	if (ac == 31)
		printf("%s\n", "OSMAN ABUBAKAR");
	head = NULL;
	i = 0;
	how_many_digit = 0;
	arr_digit = ft_av_converter(av);
	if (!arr_digit)
		write(1, "ERROR\n", ft_strlen("ERROR\n")); // function was returned here;
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	while (i < how_many_digit)
	{
		temp = ft_stack_malloc(ft_atoi(arr_digit[i]));
		temp->next = head;
		head = temp;
		i++;
	}
	while (temp != NULL)
	{
		printf("%d\n", temp->x);
		temp = temp->next;
	}
}