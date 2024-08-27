/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:18:29 by habouda           #+#    #+#             */
/*   Updated: 2024/08/27 16:57:22 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(t_double_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
void	ft_free_double_list(t_double_list **lst)
{
	t_double_list	*ptr;
	t_double_list	*temp;

	if (lst == NULL || *lst == NULL)
		return;
		
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	*lst = NULL;
}
int	sort_three_stack_reverse(t_double_list **head, char c)
{
	t_double_list	*second;
	t_double_list	*third;

	if (*head == NULL)
		return (0);
	second = (*head)->next;
	third = second->next;
	if ((*head)->value > second->value && second->value > third->value)
		return (0);
	if ((*head)->value > second->value && second->value < third->value)
	{
		if ((*head)->value > third->value)
			return (swap(*head, c), reverse_rotate(head, c), 2);
		if ((*head)->value < third->value)
			return (reverse_rotate(head, c), 1);
	}
	if ((*head)->value < second->value && second->value > third->value)
	{
		if ((*head)->value > third->value)
			return (swap(*head, c), 1);
		if ((*head)->value < third->value)
			return (rotate(head, c), 1);
	}
	return (swap(*head, c), reverse_rotate(head, c), 2);
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

int		calculate_node_pos_in_a(t_double_list **a, t_double_list *node)
{
	int 			size;
	int				i;
	t_double_list	*head;

	i = 0;
	size = ft_listsize(*a);
	head = *a;
	while (head != node)
	{
		i++;
		head = head->next;
	}
	if (size / 2 >= i)
		return (i);
	else 
		return (size - i);
}