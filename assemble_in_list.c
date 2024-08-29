/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:24:20 by habouda           #+#    #+#             */
/*   Updated: 2024/08/29 16:08:35 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*assemble_in_list(int argc, char *argv[])
{
	int				i;
	t_double_list	*head;

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
		ft_add_in_list(&head, argv[i]);
		i++;
	}
	return (head);
}

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
			if (ft_atol(argv[i]) == ft_atol(argv[k]))
				return (0);
			k++;
		}
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
int	parsing(char *pile)
{
	int	i;

	i = 0;
	while (pile[i])
	{
		if (ft_isdigit(pile[i]))
			i++;
		else if (pile[i] == '-' || pile[i] == '+')
		{
			if (pile[i + 1] && ft_isdigit(pile[i + 1]))
				i++;
			else
				return (0);
		}
		else if (pile[i] == ' ')
		{
			if (pile[i + 1] && (pile[i + 1] == '-' || pile[i + 1 == '+']))
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void	ft_free_list(t_double_list **lst)
{
	t_double_list	*ptr;
	t_double_list	*temp;

	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free (ptr);
		ptr = temp;
	}
	*lst = NULL;
}
