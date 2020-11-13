# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 05:28:15 by yberries          #+#    #+#              #
#    Updated: 2020/11/13 05:49:57 by yberries         ###   ########.fr        #
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

S_CLN	= \033[K
C_RED = \033[31m
C_CYAN = \033[36m

.PHONY: clean all re fclean

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
#@printf "\r$(S_CLN)$(C_CYAN)Assembling $< > $@"
	@gcc -c $(FLAGS) -I $(HDR_DIR) -I $(LIBFT_DIR) $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
#	@printf "$(C_RED)Remove ft_printf *.o\n"

re: clean all
