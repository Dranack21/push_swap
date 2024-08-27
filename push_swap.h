/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:28:02 by habouda           #+#    #+#             */
/*   Updated: 2024/08/27 16:57:35 by habouda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct t_double_list
{
	int						value;
	struct t_double_list	*previous;
	struct t_double_list	*next;
}	t_double_list;

t_double_list	*assemble_in_list(int argc, char *argv[]);
t_double_list	*find_biggest_node(t_double_list **lst);
t_double_list   *find_smaller_than_node(t_double_list **lst, t_double_list *node);

int			check_numbers(char **argv);
int			parsing(char *pile);
int			ft_listsize(t_double_list *lst);

int			sort_for_extremes(t_double_list **lst, char c);
int			sort_for_middle_bigger(t_double_list **lst, t_double_list *node, char c);
int 		sort_for_middle_smaller(t_double_list **lst, t_double_list *node, char c);
int			check_biggest_or_smallest(t_double_list **lst, t_double_list *node);
int			rotate_or_rev(t_double_list **a, t_double_list *a_node);
int			calculate_steps(t_double_list **b, t_double_list *node);
int			sort_three_stack_reverse(t_double_list **head, char c);
int			calculate_node_pos_in_a(t_double_list **a, t_double_list *node);

void		find_best_push(t_double_list **a, t_double_list **b, t_double_list *bi);
void		push(t_double_list **l1, t_double_list **l2, char c);
void		swap(t_double_list *head, char c);
void		rotate(t_double_list **head, char c);
void		reverse_rotate(t_double_list **head, char c);

void 		alloc_temp_list(t_double_list *src, t_double_list **dst);
void		ft_free_list(t_double_list **lst);
void		ft_lstadd_end(t_double_list **head, int value);
void		ft_add_in_list(t_double_list **head, char *argv);
void		print_list(t_double_list *head);
void		ft_free_double_list(t_double_list **lst);
void		*create_node(int value);

#endif