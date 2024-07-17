/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:50:10 by habouda           #+#    #+#             */
/*   Updated: 2024/07/17 18:30:05 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parsing(char *pile)
{
	int	i;

	i = 0;
	while(pile[i])
	{
		if (ft_isdigit(pile[i]))
			i++;
		else if(pile[i] == '-' || pile[i] == ' ' || pile[i] == '+')
		{
				if (pile[i + 1] && ft_isdigit(pile[i + 1]))
					i++;
				else 
					return (0);
		}
		else 
			return (0);
	}
	return (1);
}
