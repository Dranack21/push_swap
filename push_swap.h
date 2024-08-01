/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:55:03 by habouda           #+#    #+#             */
/*   Updated: 2024/07/31 20:36:00 by habouda          ###   ########.fr       */
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

t_double_list	*create_node(int value);
t_double_list	*assemble_in_list(int argc, char *argv[]);

void			append_node(t_double_list **head, int value);
void			print_list(t_double_list *head);
void			ft_lstadd_end(t_double_list **head, int value);
void			ft_add_in_list(t_double_list **a, char *argv);
void			ft_free_list(t_double_list **lst);
void			swap(t_double_list *head, char c);
void			push(t_double_list **l1, t_double_list **l2, char c);
void			rotate(t_double_list **head, char c);
void			reverse_rotate(t_double_list **head, char c);
void			sort_three_stack(t_double_list **head);

int				value_change(char c, int value);
int				check_numbers(char **argv);
int				parsing(char *arg);

#endif