/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:30:57 by habouda           #+#    #+#             */
/*   Updated: 2024/08/26 17:33:13 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_double_list **l1, t_double_list **l2, char c)
{
	t_double_list	*temp;

	if (*l2 == NULL)
		return;
	temp = *l2;
	*l2 = (*l2)->next;
	if (*l2) 
		(*l2)->previous = NULL;
	temp->next = *l1;
	if (*l1)
		(*l1)->previous = temp;
	*l1 = temp;
	(*l1)->previous = NULL;
	if (c == 'a')
		printf("pa\n");
	else if (c == 'b')
		printf("pb\n");
}


void swap(t_double_list *head, char c)
{
    int temp;
    t_double_list *next;

    if (!head || !head->next)
        return;

    next = head->next;
    temp = head->value;
    head->value = next->value;
    next->value = temp;

    if (c == 'a')
        ft_printf("sa\n");
    else if (c == 'b')
        ft_printf("sb\n");
    else if (c == 'c')
        ft_printf("ss\n");
}

void rotate(t_double_list **head, char c)
{
    t_double_list *temp;
    t_double_list *new_head;

    if (*head == NULL || !(*head)->next)
        return;
    temp = *head;
    new_head = (*head)->next;

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = *head;
    (*head)->previous = temp;
    (*head)->next = NULL;
    new_head->previous = NULL;
    *head = new_head;
    if (c == 'a')
        ft_printf("ra\n");
    else if (c == 'b')
        ft_printf("rb\n");
    else if (c == 'c')
        ft_printf("rr\n");
}

void reverse_rotate(t_double_list **head, char c)
{
    t_double_list *temp;

    if (*head == NULL || !(*head)->next)
        return;
    temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->previous->next = NULL;
    temp->previous = NULL;
    temp->next = *head;
    (*head)->previous = temp;
    *head = temp;
    if (c == 'a')
        ft_printf("rra\n");
    else if (c == 'b')
        ft_printf("rrb\n");
    else if (c == 'c')
        ft_printf("rrr\n");
}



