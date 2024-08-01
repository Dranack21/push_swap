/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:18:30 by habouda           #+#    #+#             */
/*   Updated: 2024/08/01 05:27:25 by habouda          ###   ########.fr       */
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


void	sort_stack(t_double_list **a, t_double_list **b)
{
	push(b, a, 'b');
	push(b, a, 'b');
}

int		cheapest_number(t_double_list **a, t_double_list **b)
{ 
	t_double_list	**c;
	t_double_list	*head;

	head = *b;
	while(head->next)
	{
		alloc_temp_list(b, c);
		ft_lstadd_end(c, head->value);
		
		ft_free_list(c);
		head = head->next;
	}
	
}

void	alloc_temp_list(t_double_list **b, t_double_list **c)
{
	t_double_list *head;

	if ((*b)->value == NULL)
		return ;
	head = *b;
	c = malloc(sizeof(t_double_list)* 3);
	if (!c)
		return ;
	while ((head->next) != NULL)
	{
		ft_lstadd_end(c, head->value);
		head = head->next;
	}
}
