/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:40 by habouda           #+#    #+#             */
/*   Updated: 2024/08/27 16:58:54 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rotate_or_rev(t_double_list **a, t_double_list *a_node)
{
	int	i;
	int	size;
	t_double_list	*head;

	if (*a == NULL)
		return (0);
	head = *a;
	i = 0;
	size = ft_listsize(*a);
	while (head != a_node)
	{
		head = head->next;
		i++;
	}
	if (size / 2 > i)
		return (2);
	return (1);
}

int		check_biggest_or_smallest(t_double_list **lst, t_double_list *node)
{
	t_double_list	*head;
	int				smallest;
	int				biggest;

	biggest = 2;
	smallest = 1;
	head = *lst;
	while (head)
	{
		if (head->value < node->value)
			smallest = 0;
		if (head->value > node->value)
			biggest = 0;
		head = head->next;
	}
	if (biggest == 2)
		return (2);
	else if (smallest == 1)
		return (1);
	return (3);
}

int		calculate_steps(t_double_list **b, t_double_list *node)
{
	t_double_list	*simulated_b;
	int				steps;
	int				size;

	steps = 0;
	simulated_b = NULL;
	alloc_temp_list(*b, &simulated_b);
	size = check_biggest_or_smallest(&simulated_b, node);
	if (size == 1 || size == 2)
	{
		steps = sort_for_extremes(&simulated_b, 'd');
	}
	else if (size == 3)
	{
	steps = sort_for_middle_bigger(&simulated_b, node, 'd');
	}
	ft_free_list(&simulated_b);
	return (steps + 1);
}

void	find_best_push(t_double_list **a, t_double_list **b, t_double_list *bi)
{
	int				steps;
	int				best_steps;
	int				size;
	t_double_list	*current;
	t_double_list	*best_node;

	best_steps = INT_MAX;
	current = *a;
	while (current)
	{
		steps = calculate_steps(b, current) + calculate_node_pos_in_a(a, current);
		if (steps < best_steps && current != bi)
		{
			best_node = current;
			best_steps = steps;
		}
		current = current->next;
	}
	// printf("best steps :%d\n", best_steps);
	if (rotate_or_rev(a, best_node) == 1)
	{
		while (*a != best_node)
			reverse_rotate(a, 'a');
	}
	else if (rotate_or_rev(a, best_node) == 2)
	{
		while (*a != best_node)
			rotate(a, 'a');
	}
	size = check_biggest_or_smallest(b, best_node);
	if (size == 3)
	{
		sort_for_middle_bigger(b, best_node, 'b');
	}
	else if (size == 1 || size == 2)
	{
		sort_for_extremes(b, 'b');
	}
	push(b, a, 'b');
}
