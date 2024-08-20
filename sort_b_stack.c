/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:40 by habouda           #+#    #+#             */
/*   Updated: 2024/08/20 13:20:13 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_biggest_or_smallest(t_double_list **lst, t_double_list *node)
{
	t_double_list	*head;
	int				smallest;
	int				biggest;

	biggest = 0;
	smallest = 0;
	head = *lst;
	while (head)
	{
		if (head->value > node->value)
			biggest = 0;
		if (head->value < node->value)
			smallest = 0;
		head = head->next;
	}
	if (biggest == 1)
		return (2);
	else if (smallest == 1)
		return (1);
	return (3);
}

int		calculate_steps(t_double_list **b, t_double_list *node)
{
	t_double_list	**simulated_b;
	int				steps;
	int				size;

	simulated_b = NULL;
	alloc_temp_list(*simulated_b, b);
	size = check_biggest_or_smallest(simulated_b, node);
	if (size == 1)
		steps == sort_for_smaller();
	else if (size == 2)
		steps == sort_for_bigger();
	else if (size == 3)
		steps == sort_for_middle();
}

void	find_best_push(t_double_list **a, t_double_list **b)
{
	int				steps;
	int				best_steps;
	t_double_list	*current;
	t_double_list	*best_node;

	best_steps = INT_MAX;
	current = *a;
	while (current)
	{
		steps = calculate_steps(b, current);
		if (steps < best_steps)
		{
			best_node = current;
			best_steps = steps;
		}
		current = current->next;
	}
}