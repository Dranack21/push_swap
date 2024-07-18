/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:45:58 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 21:01:37 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*assemble_in_list(int argc, char *argv[])
{
	int	i;
	t_double_list *head;

	head = NULL;
	i = 1;
	if (argc < 2) 
		return (head);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (argv[i])
	{ 
		if (!parsing(argv[i++]) || !check_numbers(argv))
			return (head);
	}
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		ft_add_in_list_2(&head, argv[i]);
		i++;
	}
	return (head);
}
