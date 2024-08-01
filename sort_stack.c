/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:18:30 by habouda           #+#    #+#             */
/*   Updated: 2024/08/01 04:06:58 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack(t_double_list **head)
{
	t_double_list	*second;

	if (*head == NULL)
		return ;
	second = (*head)->next;
	if ((*head)->value < second->value)
	{
		if (second->value < (second->next)->value)
			return ;
	}
	if ((*head)->value < second->value)
	{
		if (second->value > (second->next)->value)
		{
			if ((*head)->value < (second->next)->value)
				return (swap(*head, 'a'), rotate(head, 'a'));
			return (reverse_rotate(head, 'a'));
		}
	}
	if ((second->next)->value < second->value)
		return (swap(*head, 'a'), reverse_rotate(head, 'a'));
	if ((*head)->value < (second->next)->value)
		return (swap(*head, 'a'));
	return (rotate(head, 'a'));
}
