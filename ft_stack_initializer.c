/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:42:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/11 15:50:44 by bahkaya          ###   ########.fr       */
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

t_stack	*ft_stack(char const **av, int ac)
{
	t_stack		*temp;
	t_stack		*head;
	char		**arr_digit;
	int			how_many_digit;
	int			i;
	if (ac == 31)
		printf("%s\n", "OSMAN ABUBAKAR");
	temp = NULL;
	i = 0;
	how_many_digit = 0;
	arr_digit = ft_av_converter(av);
	if (!arr_digit)
		write(1, "ERROR\n", ft_strlen("ERROR\n")); // function was returned here;
	while (arr_digit[how_many_digit] != NULL)
		how_many_digit++;
	while (i < how_many_digit)
	{
		head = ft_stack_malloc(ft_atoi(arr_digit[i]));
		head->next = temp;
		temp = head;
		i++;
	}
	return (head);
}
