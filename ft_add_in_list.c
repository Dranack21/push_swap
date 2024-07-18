/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:55:43 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 02:10:47 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_in_list(t_double_list **head, char *argv)
{
	int value;
	int	i;

	i = 0;
	value = 0;
	while (argv[i])
	{
		value = value_change(argv[i], value);
		i++;
		if (argv[i] == '-' || argv[i] == '+')
		{
			i++;
			while (ft_isdigit(argv[i++]))
				value = value_change(argv[i], value);
			ft_lstadd_end(head, value);
		}
		if (argv[i] && !ft_isdigit(argv[i]))
		{
			ft_lstadd_end(head, value);
			value = 0;
			while(!ft_isdigit(argv[i]))
				i++;
		}
	}
	ft_lstadd_end(head, value);
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