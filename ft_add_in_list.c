/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:55:43 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 17:14:12 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_in_list(t_double_list **head, char *argv)
{
	int value;
	int	i;
	int sign;

	i = 0;
	value = 0;
	while (argv[i])
	{
		sign = 1;
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '+' || argv[i] == '-')
		{
			if (argv[i] == '-')
				sign = - sign;
			i++;
		}
		while(ft_isdigit(argv[i]))
		{
			value = value_change(argv[i], value);
			i++;
		}
		ft_lstadd_end(head, value * sign);
		value = 0;
	}
}

int	value_change(char c, int value)
{
	if (c && ft_isdigit(c))
	{
		value = (value * 10) + (c - '0');
		return (value);
	}
	return (0);
}