/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:25:58 by habouda           #+#    #+#             */
/*   Updated: 2024/08/31 02:17:31 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alloc_temp_list(t_double_list *src, t_double_list **dst)
{
	t_double_list	*new_node;
	t_double_list	*tail;

	tail = NULL;
	while (src)
	{
		new_node = malloc(sizeof(t_double_list));
		new_node->value = src->value;
		new_node->next = NULL;
		new_node->previous = tail;
		if (tail)
			tail->next = new_node;
		else
			*dst = new_node;
		tail = new_node;
		src = src->next;
	}
}

void	ft_lstadd_end(t_double_list **head, int value)
{
	t_double_list	*new_node;
	t_double_list	*temp;

	new_node = create_node(value);
	if (!head || !new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->previous = temp;
	}
}

void	ft_add_in_list(t_double_list **head, char *argv)
{
	ft_lstadd_end(head, ft_atoi(argv));
}

void	*create_node(int value)
{
	t_double_list	*new_node;

	new_node = (t_double_list *)malloc(sizeof(t_double_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	print_list(t_double_list *head)
{
	t_double_list	*temp;

	if (head == NULL)
		return ;
	temp = head;
	while (temp != NULL)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
