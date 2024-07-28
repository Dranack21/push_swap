/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:32:06 by habouda           #+#    #+#             */
/*   Updated: 2024/07/28 20:13:41 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_double_list *head, char c)
{
	int				temp;
	t_double_list	*next;

	if (!head || !head->next)
		return ;
	next = head->next;
	if (head != NULL)
	{
		temp = head->value;
		head->value = next->value;
		next->value = temp;
		if (c == 'a')
			ft_printf("sa\n");
		if (c == 'b')
			ft_printf("sb\n");
		if (c == 'c')
			ft_printf("ss\n");
	}
}

void	push(t_double_list **l1, t_double_list **l2, char c)
{
	t_double_list	*new;
	t_double_list	*temp;

	if (*l2 != NULL)
	{
		temp = *l2;
		new = malloc(sizeof(t_double_list));
		if (!new)
			return ;
		new->value = (*l2)->value;
		new->previous = NULL;
		new->next = *l1;
		*l1 = new;
		*l2 = (*l2)->next;
		free(temp);
		if (c == 'a')
			ft_printf("pa\n");
		if (c == 'b')
			ft_printf("pb\n");
	}
}

void	rotate(t_double_list **head, char c)
{
	t_double_list	*temp;
	t_double_list	*new_head;

	if (*head == NULL || !(*head)->next)
		return ;
	temp = *head;
	new_head = (*head)->next;
	while ((*head)->next)
	{
		*head = (*head)->next;
	}
	(*head)->next = temp;
	temp->previous = *head;
	temp->next = NULL;
	new_head->previous = NULL;
	*head = new_head;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
	if (c == 'c')
		ft_printf("rr\n");
}

void	reverse_rotate(t_double_list **head, char c)
{
	t_double_list	*temp;
	int				i;

	if (*head == NULL || !(*head)->next)
		return ;
	temp = *head;
	i = 0;
	while ((*head)->next)
	{
		*head = (*head)->next;
		i++;
	}
	while (i > 0)
	{
		rotate(&temp, 'd');
		i--;
	}
	c = c + 1;
}
