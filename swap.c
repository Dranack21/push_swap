/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:32:06 by habouda           #+#    #+#             */
/*   Updated: 2024/07/25 19:17:53 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	swap(t_double_list *head, int i)
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
		if (i == 0)
		{
			ft_printf("sa\n");
		}
		else
			ft_printf("sb\n");
	}
}

void	push(t_double_list *a, t_double_list *b, int i)
{
	
}