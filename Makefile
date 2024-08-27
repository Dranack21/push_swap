# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habouda <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 01:37:02 by Habouda           #+#    #+#              #
#    Updated: 2024/08/26 19:52:30 by habouda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COMPIL #####################################################################

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
NAME 	= push_swap

### SRC ########################################################################

SRCS	=	assemble_in_list.c \
			calculate_steps.c \
			commands.c \
			list_utils.c \
			list_utils2.c \
			push_swap.c \
			sort_b_stack.c \

### OBJS ###########################################################################
			
OBJS	= $(SRCS:.c=.o)

### LIBFT ###########################################################################

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

### COMMANDS #######################################################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@rm -f $(OBJS)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all re fclean clean 
