/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:02 by habouda           #+#    #+#             */
/*   Updated: 2024/08/27 16:38:32 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_double_list	*head;
	t_double_list	*no;
	t_double_list	*biggest_node;

	head = assemble_in_list(argc, argv);
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
	ft_free_list(&head);
	ft_free_list(&no);
}