/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:32:06 by habouda           #+#    #+#             */
/*   Updated: 2024/07/28 18:04:17 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_double_list *head, char c)
{
	int				temp;
	t_double_list	*next;

	if (head)
		next = head->next;
	if (head != NULL)
	{
		temp = head->value;
		head->value = next->value;
		next->value = temp;
		if (c == 'a')
		{
			ft_printf("sa\n");
		}
		else
			ft_printf("sb\n");
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
			ft_printf("pa");
		if (c == 'b')
			ft_printf("pb");
	}
}
