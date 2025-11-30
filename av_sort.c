/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:39:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/30 17:52:07 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_error_return_stack(char **arr_digit, t_stack *head)
{
	write(2, "Error\n", 6);
	ft_free(arr_digit);
	free_stack(head);
	exit(-1);
}
void	ft_error_return_pointer(char **arr_digit)
{
	write(2, "Error\n", 6);
	ft_free(arr_digit);
	exit(-1);
}

void ft_free(char **str_is_digit)
{
	int	i;

	i = 0;
	while (str_is_digit[i] != NULL)
	{
		free(str_is_digit[i]);
		i++;
	}
	free(str_is_digit);
}
void ft_check_for_max(char **arr_is_digit)
{
	int	i;
	long value;

	value = 0;
	i = 0;
	while(arr_is_digit[i] != NULL)
	{
		value = ft_atoi(arr_is_digit[i]);
		if (value > 2147483647 || value < -2147483648)
			ft_error_return_pointer(arr_is_digit);
		i++;
	}
}

char	**ft_av_converter(char const **av)
{
	int		i;
	int		k;
	char	**arr_is_digit;

	k = 0;
	i = 0;
	arr_is_digit = ft_split(av[1], ' ');
	ft_check_for_max(arr_is_digit);
	while (arr_is_digit[k] != NULL)
	{
		if(arr_is_digit[k][i] == '+' || arr_is_digit[k][i] == '-')
			i++;
		while (arr_is_digit[k][i] != '\0' )
		{
			if (ft_isdigit(arr_is_digit[k][i]))
				i++;
			else
				ft_error_return_pointer(arr_is_digit);
		}
		k++;
	}
	return (arr_is_digit);
}
