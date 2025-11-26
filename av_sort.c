/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:39:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/26 21:36:49 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**ft_av_converter(char const **av, int *flag)
{
	int		i;
	int		k;
	char	**arr_is_digit;

	k = 0;
	i = 0;
	arr_is_digit = ft_split(av[1], ' ');
	while (arr_is_digit[k] != NULL)
	{
		if(arr_is_digit[k][i] == '+' || arr_is_digit[k][i] == '-')
			i++;
		// if(arr_is_digit[k][i] == '\0') bunun olmaması gerekiyor!
		// {
		// 	write(2, "Error\n", 6);
		// 	ft_free(arr_is_digit);
		// 	exit(-1);
		// }
		while (arr_is_digit[k][i] != '\0' )
		{
			if (ft_isdigit(arr_is_digit[k][i]))
				i++;
			else
			{
				*flag = 5;
				return (arr_is_digit);
			}
		}
		k++;
	}
	return (arr_is_digit);
}
