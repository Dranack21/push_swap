/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:18:30 by habouda           #+#    #+#             */
/*   Updated: 2024/08/04 20:22:18 by habouda          ###   ########.fr       */
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

int	sort_three_stack_reverse(t_double_list **head)
{
	t_double_list	*second;
	int				commands;

	if (*head == NULL)
		return (0);
	second = (*head)->next;
	commands = 0;
	if ((*head)->value > second->value && second->value > second->next->value)
		return (0);
	if ((*head)->value > second->value && second->value < second->next->value)
	{
		if ((*head)->value > second->next->value)
			return (swap(*head, 'd'), rotate(head, 'd'),	commands + 2);
		return (reverse_rotate(head, 'd'),	commands + 1);
	}
	if (second->next->value > second->value)
		return (swap(*head, 'd'), reverse_rotate(head, 'd'),	commands + 2);
	if ((*head)->value > second->next->value)
		return (swap(*head, 'd'),	commands + 1);
	return (rotate(head, 'd'),	commands + 1);
}

t_double_list	*simulate_push(t_double_list *b_head, int value)
{
	t_double_list *new_node;

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
	t_double_list	**simulated_b;
	int				sort_steps;

	simulated_b = NULL;
	alloc_temp_list(b, simulated_b);
	ft_lstadd_end(simulated_b, a_node->value);
	sort_steps = sort_three_stack_reverse(simulated_b);
	ft_free_list(simulated_b);
	return (sort_steps);
}

void	find_best_push(t_double_list **a, t_double_list **b)
{
	int				best_steps;
	int				steps;
	t_double_list	*best_node;
	t_double_list	*current;

	best_steps = INT_MAX;
	current = *a;
	while (current)
	{
		 steps = calculate_total_steps(b, current);
		if (steps < best_steps)
		{
			best_steps = steps;
			best_node = current;
		}
		current = current->next;
	}
	if (best_node)
	{
		while (*a != best_node)
			rotate(a, 'a'); 
		push(b, a, 'b');
		sort_three_stack_reverse(b);
	}
}

void	alloc_temp_list(t_double_list **b, t_double_list **c)
{
	t_double_list	*head;
	int				i;

	if (!(*b))
		return ;
	i = 1;
	head = *b;
	while(head->next)
	{
		i++;
		head = head->next;
	}
	head = *b;
	c = malloc(sizeof(t_double_list)* i);
	if (!c)
		return ;
	while ((head->next) != NULL)
	{
		ft_lstadd_end(c, head->value);
		head = head->next;
	}
}