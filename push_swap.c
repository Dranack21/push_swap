/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:40 by habouda           #+#    #+#             */
/*   Updated: 2024/07/17 20:36:36 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	t_double_list **a;
	
	i = 1;
	if (argc < 2) 
		return (0);
	while (argv[i])
	{ 
		if (!parsing(argv[i++]))
				return (0);
	}
	i = 1;
	if (argv = 2)
		ft_add_in_list(a, argv);
		
	if (argv > 2)
	{
		while (argv[i++])
			ft_add_in_list_2(a, argv[i]);
	}
}
