# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 05:28:15 by yberries          #+#    #+#              #
#    Updated: 2020/10/10 23:46:48 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = libft/
LIBFT_LNK = -L $(LIBFT_DIR) -lft

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRCS1 = push_swap.c \
		ps_tools.c\
		swaps.c\
		sorting.c\
		reading.c\
		lst_tools.c\
		out_tools.c
SRCS2 = checker.c\
		lst_tools.c\
		reading.c\
		ps_tools.c\
		out_tools.c

OBJ_DIR = obj/
OBJS1 = $(patsubst %.c, %.o, $(SRCS1))
OBJS2 = $(patsubst %.c, %.o, $(SRCS2))
OBJ1 = $(addprefix $(OBJ_DIR), $(OBJS1))
OBJ2 = $(addprefix $(OBJ_DIR), $(OBJS2))

HDRS = push_swap.h
HDR_DIR = include/
HDR = $(addprefix $(HDR_DIR), $(HDRS))

INCLUDES = -I $(HDR_DIR) -I $(LIBFT_DIR)

FLAGS = -Wall -Wextra #!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

S_CLN = \033[K
C_RED = \033[31m
C_GRN = \033[32m
C_CYAN = \033[36m

.PHONY: clean all re fclean

all: $(LIBFT) $(OBJ_DIR) $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	@gcc $(FLAGS) -o $(NAME1) $(INCLUDES) $(OBJ1) $(LIBFT_LNK)
	@printf "\r$(S_CLN)$(C_GRN)$(NAME1) compiled\n"

$(NAME2): $(OBJ2)
	@gcc $(FLAGS) -o $(NAME2) $(INCLUDES) $(OBJ2) $(LIBFT_LNK)
	@printf "\r$(S_CLN)$(C_GRN)$(NAME2) compiled\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	@printf "\r$(S_CLN)$(C_CYAN)Compiling"
	@gcc $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	@make -sC $(LIBFT_DIR) clean
	@printf "$(C_RED)Remove push_swap *.o\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME1)
	@printf "$(C_RED)Remove $(NAME1)\n"
	@rm -f $(NAME2)
	@printf "$(C_RED)Remove $(NAME2)\n"
	@make -sC $(LIBFT_DIR) fclean
	
re: fclean all
