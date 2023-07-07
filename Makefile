# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 14:38:00 by fpinho-d          #+#    #+#              #
#    Updated: 2023/07/07 18:14:04 by fpinho-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAND = push_swap.c helpers.c check_array.c sorting_process.c sort_helpers.c sort_small.c sort_big.c sort_actions.c sort_actions2.c max_min.c error_file.c
OBJ_MAND = $(MAND:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ_MAND)
	cc -g $(CFLAGS) $(OBJ_MAND) -o $(NAME)

clean:
	rm -rf $(OBJ_MAND)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(NAME)
