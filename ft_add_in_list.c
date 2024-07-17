/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_in_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:55:43 by habouda           #+#    #+#             */
/*   Updated: 2024/07/17 21:06:21 by habouda          ###   ########.fr       */
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
		if (ft_isdigit(argv[i]))
		{
			value = ft_atoi(&argv[i]) + value * 10 ;
			i++;
		}
		else 
		{
			value = 0;
			ft_lstadd_end(head, value);
			i++;
		}
	}
		ft_lstadd_end(head, ft_atoi(argv));
}
