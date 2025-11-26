/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_argv_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:29:25 by bahkaya           #+#    #+#             */
/*   Updated: 2025/11/26 16:40:54 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_check_for_same_number(char const **av, int number, int ac)
{
	int	k;
	int len;

	len = 0;
	k = 0;
	while(k < ac) // Burası sıkıntılı doğru değil parse düzgün yap aq!
	{
		if(number == ft_atoi(av[k]))
			len++;
		k++;
	}
	if (len != 1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
}
void	ft_error_check_n_argv(char const **av)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	while (av[k] != NULL)
	{
		i = 0;
		if (av[k][i] == '+' || av[k][i] == '-')
			i++;
		if (av[k][i] == '\0')
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		while (av[k][i] != '\0')
		{
			if(ft_isdigit(av[k][i]))
				i++;
			else if (!ft_isdigit(av[k][i]))
			{
				write(2, "Error\n", ft_strlen("Error\n"));
				exit(-1);
			}
		}
		k++;
	}
}

char **ft_n_av_converter(char const **av, int ac)
{
	char	**arr_digit;
	int		i;
	int		k;
	int		len;

	i = 0;
	k = 1;
	len = 0;
	while(k < ac) // Burası sıkıntılı doğru değil parse düzgün yap aq!
	{
		len = ft_atoi(av[k]);
		ft_check_for_same_number(av, len, ac);
		k++;
	}
	arr_digit = malloc(sizeof(char *) * ac);
	if (!arr_digit)
	{
		write(2, "Error\n", 6);
		ft_free(arr_digit); // kontrol et buna gerek yok olsa gerek
		exit(-1);
	}
	if (len != 1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	while (k < ac)
	{
		len = ft_strlen(av[ac - 1]);
		arr_digit[i] = ft_substr(av[ac - 1], 0, len);
		i++;
		ac--;
	}
	arr_digit[i + 1] = NULL;
	return(arr_digit);
}

t_stack *ft_n_stack_a(char const **av, int ac)
{
	t_stack	*head;
	t_stack	*temp;
	char	**arr_digit;
	int		i;

	temp = NULL;
	i = 0;
		
	ft_error_check_n_argv(av);
	arr_digit = ft_n_av_converter(av, ac);
	i = 0;
	while (i < ac - 1)
	{
		head = ft_stack_malloc_a(ft_atoi(arr_digit[i]), arr_digit);
		if(!head)
		{
			write(2, "Error\n", 6);
			ft_free(arr_digit);
			free_stack(head);
			exit(-1);
		}
		head->next = temp;
		temp = head;
		i++;
	}
	ft_free(arr_digit);
	return (head);
}
