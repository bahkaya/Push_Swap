/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:39:39 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/06 19:59:36 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_free(char **str_is_digit)
{
	int	i;

	i = 0;
	while (str_is_digit[i] != NULL)
		free(str_is_digit[i]);
	free(str_is_digit);
}

char	**ft_av_converter(char const **av)
{
	int		i;
	int		k;
	char	**arr_is_digit;
	
	k = 0;
	i = 0;
	arr_is_digit = ft_split(av[1], ' ');
	while (arr_is_digit[k] != NULL)
	{
		while (arr_is_digit[k][i] != '\0' )
		{
			if (ft_isdigit(arr_is_digit[k][i]))
				i++;
			else
			{
				ft_free(arr_is_digit);
				return (0);
			}
		}
		k++;
	}
	return (arr_is_digit);
}
