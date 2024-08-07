/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:18:30 by habouda           #+#    #+#             */
/*   Updated: 2024/08/07 21:52:57 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_double_list	*simulate_push(t_double_list *b_head, int value)
{
	t_double_list	*new_node;

	new_node = malloc(sizeof(t_double_list));
	new_node->value = value;
	new_node->next = b_head;
	new_node->previous = NULL;
	if (b_head)
		b_head->previous = new_node;
	return (new_node);
}

int	calculate_total_steps(t_double_list **b, t_double_list *a_node)
{
	t_double_list	*simulated_b;
	int				sort_steps;

	simulated_b = NULL;
	alloc_temp_list(*b, &simulated_b);
	ft_lstadd_end(&simulated_b, a_node->value);
	sort_steps = sort_three_stack_reverse(&simulated_b, 'd');
	ft_free_list(&simulated_b);
	return (sort_steps);
}

void	alloc_temp_list(t_double_list *src, t_double_list **dst)
{
	t_double_list	*new_node;
	t_double_list	*last;

	while (src)
	{
		new_node = malloc(sizeof(t_double_list));
		if (!new_node)
			return ;
		new_node->value = src->value;
		new_node->next = NULL;
		new_node->previous = NULL;
		if (*dst == NULL)
		{
			*dst = new_node;
		}
		else
		{
			last = *dst;
			while (last->next)
				last = last->next;
			last->next = new_node;
			new_node->previous = last;
		}
		src = src->next;
	}
}

void	find_best_push(t_double_list **a, t_double_list **b)
{
	int				best_steps;
	int				steps;
	int				i;
	t_double_list	*best_node;
	t_double_list	*current;

	best_steps = INT_MAX;
	current = *a;
	i = 0;
	while (current)
	{
		steps = calculate_total_steps(b, current) + i;
		if (steps < best_steps)
		{
			best_steps = steps;
			best_node = current;
			i++;
		}
		current = current->next;
	}
	while (*a != best_node)
		rotate(a, 'a');
	push(b, a, 'b');
	sort_three_stack_reverse(b, 'b');
}
