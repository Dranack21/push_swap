/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:55:03 by habouda           #+#    #+#             */
/*   Updated: 2024/07/17 19:52:10 by habouda          ###   ########.fr       */
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

int	parsing(char *pile);

void	ft_lstadd_back(t_list **head, int value);

t_double_list	*create_node(int value);

#endif