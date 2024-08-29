/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:02 by habouda           #+#    #+#             */
/*   Updated: 2024/08/29 19:31:17 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_cases(t_double_list **a, t_double_list **b)
{
	t_double_list	*head;

	head = *a;
	if (1)
	{
		while ((head) && head->next)
		{
			if (head->value < (head->next)->value)
				head = head->next;
			else
				break;
		}
		if (head->next == NULL)
			return (1);
	}
	if (ft_listsize(*a) == 3)
	{
		sort_three_stack(a);
		return (1);
	}
	else if (ft_listsize(*a) == 5)
	{
		sort_five_stack(a, b);
		return (1);
	}
	return (0);
}

void sort_five_stack(t_double_list **a, t_double_list **b)
{
	int				i;

	i = 2;
	while (i != 0)
	{
		if (rotate_or_rev(a, find_smallest_node(a)) == 1)
		{
			while ((*a) != find_smallest_node(a))
				reverse_rotate(a, 'a');
		}
		else if (rotate_or_rev(a, find_smallest_node(a)) == 2)
		{
			while ((*a) != find_smallest_node(a))
				rotate(a, 'a');
		}
		push(b, a, 'b');
		i--;
	}
	sort_three_stack(a);
	push(a ,b, 'a');
	push(a ,b, 'a');
}

int	main(int argc, char *argv[])
{
	t_double_list	*head;
	t_double_list	*no;
	t_double_list	*biggest_node;

	if (argc == 1)
		return (0);
	head = assemble_in_list(argc, argv);
	if (head == NULL)
		return (write(2, "Error\n", 6), 0);
	if (check_cases(&head, &no))
		return (ft_free_list(&head), 0);
	biggest_node = find_biggest_node(&head);
	no = NULL;
	if (head == biggest_node)
		rotate(&head, 'a');
	push(&no, &head, 'b');
	while (ft_listsize(head) > 1)
		find_best_push(&head, &no, biggest_node);
	sort_for_extremes(&no, 'b');
	while(ft_listsize(no) > 0)
		push(&head, &no, 'a');
	// print_list(head);
	ft_free_list(&head);
	ft_free_list(&no);
}
