/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:35:37 by habouda           #+#    #+#             */
/*   Updated: 2024/08/07 21:35:50 by habouda          ###   ########.fr       */
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