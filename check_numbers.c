/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:03 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 18:34:39 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i] && argv[i + 1])
	{
		k = i + 1;
		while (k < argc)
		{
			if (ft_atoi(argv[i]) ==ft_atoi(argv[k]))
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}
