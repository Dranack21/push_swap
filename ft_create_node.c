/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:11:07 by habouda           #+#    #+#             */
/*   Updated: 2024/07/17 19:51:26 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*create_node(int value)
{
	t_double_list *new_node;
	new_node =(t_double_list *)malloc(sizeof(t_double_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
    new_node->previous = NULL;
    new_node->next = NULL;
    return new_node;
}

