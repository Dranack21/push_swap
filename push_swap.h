/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:55:03 by habouda           #+#    #+#             */
/*   Updated: 2024/07/18 01:52:26 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct t_double_list
{
	int						value;
	struct t_double_list	*previous;
	struct t_double_list	*next;
}	t_double_list;

t_double_list *create_node(int value);
void append_node(t_double_list **head, int value);
void print_list(t_double_list *head);
int parsing(char *arg);
void	ft_lstadd_end(t_double_list **head, int value);
void ft_add_in_list(t_double_list **a, char *argv);
void ft_add_in_list_2(t_double_list **a, char *argv);
void print_list(t_double_list *head);
int	value_change(char c, int value);

#endif