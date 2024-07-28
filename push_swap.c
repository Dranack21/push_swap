/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:40 by habouda           #+#    #+#             */
/*   Updated: 2024/07/28 20:10:34 by habouda          ###   ########.fr       */
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
	int				i;

	i = 0;
	head = assemble_in_list(argc, argv);
	no = assemble_in_list(argc, argv);
	ft_free_list(&no);
	push(&no, &head, 'b');
	push(&no, &head, 'b');
	push(&no, &head, 'b');
	print_list(no);
	print_list(head);
	reverse_rotate(&no, 'b');
	print_list(no);
	swap(no, 'b');
	print_list(no);
	print_list(head);
	ft_free_list(&head);
	ft_free_list(&no);
}

