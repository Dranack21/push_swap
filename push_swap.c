/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:40 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 20:37:28 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	t_double_list *head = NULL;
	
	i = 1;
	if (argc < 2) 
		return (0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (argv[i])
	{ 
		if (!parsing(argv[i++]) || !check_numbers(argv))
				return (0);
	}
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		ft_add_in_list_2(&head, argv[i]);
		i++;
	}
	print_list(head);
}
