/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:59:54 by bahkaya           #+#    #+#             */
/*   Updated: 2025/10/05 18:53:35 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
typedef struct s_node
{
	int x;
	struct s_node *next;
}	t_node;
int main(int ac, char **av)
{
	char	**new_str;
	int		i;
	int		hold_int;
	i = 0;
	if (ac == 2)
	{
		while (av[1][i] != '\0')
		{
			if (ft_isdigit(av[1][i]))
				i++;
			else
				return (write(1, &"ERROR\n", ft_strlen("ERROR\n")));
		}
		int *x = malloc (sizeof(int) * i);
		i = 0;
		new_str = ft_split(av[1], ' ');
		while (new_str[i] != NULL)
		{
			hold_int = ft_atoi(new_str[i]);
			x[i] = hold_int;
			i++;
		}
		i = 0;
		while (new_str[i] != NULL)
			free(new_str[i]);
		free(new_str);
		i = sizeof(x) / sizeof(x[0]);
		int start = 0;
		while (start <= i)
			printf("%d\n", x[i]);
		
		
	}
}
