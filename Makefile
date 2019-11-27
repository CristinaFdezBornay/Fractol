# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crfernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 11:38:43 by crfernan          #+#    #+#              #
#    Updated: 2019/06/04 14:26:50 by crfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME)
.PHONY: clean
.PHONY: fclean
.PHONY: re

VPATH:= ./sources/ ./objects/ ./includes/

NAME := fractol

CC := gcc
FRAMEWORK := -framework OpenGL -framework AppKit
LIB := libft/libft.a minilibx/libmlx.a
INCLUDES := -I minilibx/ -I includes/ -I libft/includes/
FLAGS := -Wall -Wextra -Werror -O3

SRCS_PATH := ./sources/
OBJS_PATH := ./objects/
INCL_PATH := ./includes/

SRCS_NAME := \
main.c \
helpers.c \
interactions.c \
allocation.c \
drawing.c \
calculation.c \
julias.c \
mandelbrots.c \
other_shit.c \
change_params.c
OBJS_NAME := $(SRCS_NAME:.c=.o)
INCL_NAME := \
fractol.h

SRCS := $(patsubst %,$(SRCS_PATH)%,$(SRCS_NAME))
OBJS := $(patsubst %,$(OBJS_PATH)%,$(OBJS_NAME))
INCL := $(patsubst %,$(INCL_PATH)%,$(INCL_NAME))

all: $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo [CC] $<
	@$(CC) $(FLAGS) -o $@ -c $< $(INCLUDES)

$(NAME): $(OBJS)
	@make -C libft/
	@make -C minilibx/
	@$(CC) $(FLAGS) -o $@ $^ $(LIB) $(FRAMEWORK)
	@echo "[Fractol Compiled]"

clean:
	@make -C libft/ clean
	@make -C minilibx/ clean
	@/bin/rm -f $(OBJS)
	@echo "[Fractol Objects Removed]"

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@echo "[Fractol Removed]"

norme:
	@norminette $(SRCS) $(INCL)

re: fclean all
