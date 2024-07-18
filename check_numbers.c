/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:03 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 20:36:00 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i] && argv[i + 1])
	{
		k = i + 1;
		while (argv[k])
		{
			if (ft_atoi(argv[i]) ==ft_atoi(argv[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
