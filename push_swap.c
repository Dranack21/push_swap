/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:21:02 by habouda           #+#    #+#             */
/*   Updated: 2024/08/25 20:16:09 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_double_list	*head;
	t_double_list	*no;
	// int				size;

	head = assemble_in_list(argc, argv);
	no = NULL;
	push(&no, &head, 'b');
	push(&no, &head, 'b');
	// size = ft_listsize(head);
	find_best_push(&head, &no);
	find_best_push(&head, &no);
	find_best_push(&head, &no);
	sort_three_stack_reverse(&no, 'b');
	while (ft_listsize(head) > 0)
		find_best_push(&head, &no);
	sort_for_extremes(&no, 'b');
	while(ft_listsize(no) > 0)
		push(&head, &no, 'a');
	print_list(head);
	ft_free_list(&head);
	ft_free_list(&no);
}