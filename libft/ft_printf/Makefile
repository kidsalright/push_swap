# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 05:28:15 by yberries          #+#    #+#              #
#    Updated: 2020/09/21 18:56:23 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ../libft.a
LIBFT_DIR = ../
LIBFT_LNK = -L $(LIBFT_DIR) -lft

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRCS = ft_printf.c\
	   flags.c\
	   tools.c\
	   tools_width.c\
	   type_s.c\
	   type_p.c\
	   type_d.c\
	   type_o.c\
	   type_u.c\
	   type_x.c\
	   type_f.c

OBJ_DIR = obj/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(OBJS))

HDRS = ft_printf.h\
	   structs.h
HDR_DIR = include/
HDR = $(addprefix $(HDR_DIR), $(HDRS))

INCLUDES = -I $(HDR_DIR) -I $(LIBFT_DIR)

FLAGS = -Wall -Wextra -Werror

C_CYAN = \033[36m
C_RED = \033[31m

.PHONY: clean all re fclean

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@printf "\r$(C_CYAN)Compiling ft_printf\n"
	@gcc -c $(FLAGS) $(LIBFT_LNK) -I $(HDR_DIR) -I $(LIBFT_DIR) $< -o $@

clean:
	@printf "\r$(C_RED)Clean ft_printf\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "\r$(C_RED)Fclean ft_printf\n"
	@rm -rf $(NAME)

re: fclean all
