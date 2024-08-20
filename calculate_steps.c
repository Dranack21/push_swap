/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:16:01 by habouda           #+#    #+#             */
/*   Updated: 2024/08/20 15:57:24 by habouda          ###   ########.fr       */
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

int sort_for_middle(t_double_list **lst, t_double_list *node, char c)
{
    int steps = 0;
    int size;
    int i = 0;

    t_double_list *head = *lst;
    size = ft_listsize(*lst);
    printf("Sorting for middle, list size: %d, node value: %d\n", size, node->value);
    while (head->value > node->value)
    {
        i++;
        head = head->next;
    }
    printf("i: %d\n", i);

    if (size / 2 >= i)
    {
        while (i-- > 0)
        {
            printf("before I rotate\n");
            rotate(lst, c);
            steps++;
        }
    }
    else if (size / 2 < i)
    {
        while (size - i != 0)
        {
			size --;
			printf("priout");
            reverse_rotate(lst, c);
            steps++;
        }
    }
    printf("Steps taken: %d\n", steps);

    return steps;
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
		i++;
	if (size / 2 > i)
	{
		while (head->value != biggest_node->value && steps++ > -1)
			rotate(lst ,c);
	}
	if (size / 2 <= i)
	{
		while (head->value != biggest_node->value && steps++ > -1)
			reverse_rotate(lst ,c);
	}
	return (steps);
}
