/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:24:20 by habouda           #+#    #+#             */
/*   Updated: 2024/08/29 19:09:12 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*assemble_in_list(int argc, char *argv[])
{
	int				i;
	char			**av;
	t_double_list	*head;

	av = argv;
	head = NULL;
	i = 1;
	if (argc < 2)
		return (head);
	if (argc == 2)
	{
		i = 0;
		av = ft_split(av[1], ' ');
	}
	while (av[i] != NULL)
	{
		if (!parsing(av[i++]) || !check_numbers(av))
		{
			if (argc == 2)
				ft_free_str_array(&av);
			return (head);
		}
	}
	i = 1;
	if (argc == 2)
		i = 0;
	while (av[i])
	{
		ft_add_in_list(&head, av[i++]);
	}
	if (argc == 2)
		ft_free_str_array(&av);
	return (head);
}

void	ft_free_str_array(char ***array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while ((*array)[i])
	{
		free((*array)[i]);
		((*array)[i]) = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
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
		else if (ft_is_space(pile[i]))
		{
			if (pile[i + 1] && (pile[i + 1] == '-' || pile[i + 1 == '+']))
				i++;
			else
				return (0);
		}
		else if (!ft_isdigit(pile[i]))
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
