# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 12:37:43 by dmisnich          #+#    #+#              #
#    Updated: 2018/01/26 11:39:24 by dmisnich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I ./includes/

SRCS =	src/wolf3d.c \
		src/exit.c \
		src/init.c \
		src/file.c \
		src/ray.c \
		src/move.c \
		src/key.c \
		src/texture.c \
		src/draw.c \
		./get_next_line/get_next_line.c \


OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

#minilibx
MLX_DIR = ./miniLibX/
MLX_LNK = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

debug:
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(LFT_LNK) $(MLX_LNK)
derun: debug
	lldb ./$(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(MLX_LNK) $(LFT_LNK) $(OBJ) -g -o $(NAME)

clean:
	@make -C $(LFT_DIR) clean
	@make -C $(MLX_DIR)
	@rm -f src/*.o
	@rm -f fractols/*.o
	@rm -rf ./*.dSYM

norme:
	@echo "|--------------------------------------------------|"
	@echo "|-------------------Checking header files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./includes
	@echo "|--------------------------------------------------|"
	@echo "--------------------Checking source files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./src
	@echo "|--------------------------------------------------|"
	@echo "|-----------------Checking fractols files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./fractols


fclean: clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all
