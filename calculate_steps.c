/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:16:01 by habouda           #+#    #+#             */
/*   Updated: 2024/08/25 20:16:01 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*find_biggest_node(t_double_list **lst)
{
	int				value;
	t_double_list	*head;
	t_double_list	*biggest_node;

	head = *lst;
	value = 0;
	if (head == NULL)
		return (NULL);
	while (head)
	{
		if (head->value > value)
		{
			value = head->value;
			biggest_node = head;
		}
		head = head->next;
	}
	return (biggest_node);
}
int sort_for_middle_smaller(t_double_list **lst, t_double_list *node, char c)
{
    int steps = 0;
    int size;
    int i = 0;

    t_double_list *head = *lst;
    size = ft_listsize(*lst);
    while (head->value > node->value)
    {
        i++;
        head = head->next;
    }
    if (size / 2 >= i)
    {
        while (i-- > 0)
        {
            rotate(lst, c);
            steps++;
        }
    }
    else if (size / 2 < i)
    {
        while (size - i != 0)
        {
			size --;
            reverse_rotate(lst, c);
            steps++;
        }
    }
    return (steps);
}

int sort_for_middle_bigger(t_double_list **lst, t_double_list *node, char c)
{
   	int steps = 0;
    int size;
    int i = 0;

	steps = sort_for_extremes(lst, c);
    t_double_list *head = *lst;
    size = ft_listsize(*lst);
    while (head->value > node->value)
    {
        i++;
        head = head->next;
    }
    if (size / 2 >= i)
    {
        while (i-- > 0)
        {
            rotate(lst, c);
            steps++;
        }
    }
    else if (size / 2 < i)
    {
        while (size - i != 0)
        {
			size --;
            reverse_rotate(lst, c);
            steps++;
        }
    }
    return (steps);
}

int	sort_for_extremes(t_double_list **lst, char c)
{
	int				steps;
	int				size;
	int				i;
	t_double_list	*head;
	t_double_list	*biggest_node;

	head = *lst;
	i = 0;
	steps = 0;
	biggest_node = find_biggest_node(lst);
	size = ft_listsize(*lst);
	while (head->value != biggest_node->value)
	{
		head = head->next;
		i++;
	}
	if (size / 2 > i)
	{
		while ((*lst)->value != biggest_node->value && steps++ > -1)
			rotate(lst ,c);
	}
	if (size / 2 <= i)
	{
		while ((*lst)->value != biggest_node->value && steps++ > -1)
			reverse_rotate(lst ,c);
	}
	return (steps);
}
