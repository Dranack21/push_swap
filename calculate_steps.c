/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:16:01 by habouda           #+#    #+#             */
/*   Updated: 2024/08/26 18:20:28 by habouda          ###   ########.fr       */
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
    int             i;
   	t_double_list   *smaller_node;
    t_double_list   *head;

    i = 0;
    smaller_node = find_smaller_than_node(lst, node);
    head = *lst;
    while (head != smaller_node && i++ > -1)
        head = head->next;
    if (ft_listsize(*lst) / 2 >= i)
    {
        i = 0;
        while (*lst != smaller_node && i++ > -1)
            rotate(lst ,c);
    }
    else if (ft_listsize(*lst) / 2 <= i)
    {
        i = 0;
        while (*lst != smaller_node && i++ > -1)
            reverse_rotate(lst ,c);
    }
    return (i);
}

t_double_list   *find_smaller_than_node(t_double_list **lst, t_double_list *node)
{
    int             i;
    t_double_list   *head;
    t_double_list   *best_node;

    i = INT_MAX;
    head = *lst;
    while (head)
    {
        if (head->value < node->value)
        {
            if (node->value - head->value < i)
            {
                best_node = head;
                i = node->value - head->value;
            }
        }
        head = head->next;
    }
    return (best_node);
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
