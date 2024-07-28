/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:25:40 by habouda           #+#    #+#             */
/*   Updated: 2024/07/28 18:04:03 by habouda          ###   ########.fr       */
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

	no = NULL;
	head = assemble_in_list(argc, argv);
	push(&no, &head, 'a');
	print_list(no);
	print_list(head);
	ft_free_list(&head);
	ft_free_list(&no);
}
