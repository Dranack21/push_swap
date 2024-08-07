/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:40 by habouda           #+#    #+#             */
/*   Updated: 2024/08/07 21:23:15 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_list(t_double_list **lst)
{
	t_double_list	*ptr;
	t_double_list	*temp;

	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		free (ptr);
		ptr = temp;
	}
	*lst = NULL;
}

int	main(int argc, char *argv[])
{
	t_double_list	*head;
	t_double_list	*no;

	head = assemble_in_list(argc, argv);
	no = NULL;
	push(&no, &head, 'b');
	push(&no, &head, 'b');
	find_best_push(&head, &no);
	print_list(head);
	print_list(no);
	ft_free_list(&head);
	ft_free_list(&no);
}
