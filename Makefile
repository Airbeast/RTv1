# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbeast <chbeast@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:04:50 by chbeast           #+#    #+#              #
#    Updated: 2020/07/22 20:01:51 by chbeast          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SOURCE = main.c init.c start_kernel.c make_scene.c hooks.c make_scene2.c

OBJ = $(SOURCE:.c=.o)

HEADER = rtv1.h

LIBFT_DIR = ./libft

MINILIB_DIR = ./minilibx_macos

LIBFT = ./libft/libft.a

MINILIB = ./minilibx_macos/libmlx.dylib

FRAMEWORKS = -framework OpenGL -framework AppKit -framework OpenCL

CFLAGS = -Wall -Werror -Wextra -Wno-deprecated-declarations

CC = gcc

all: $(LIBFT) $(MINILIB) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MINILIB):
	make -C $(MINILIB_DIR)

$(NAME): $(LIBFT) $(MINILIB) $(OBJ)
	$(CC) -g $(OBJ) -I $(HEADER) -I $(LIBFT_DIR) -L $(MINILIB_DIR) -lmlx -L $(LIBFT_DIR) -lft $(FRAMEWORKS) -o $(NAME)
	install_name_tool -change libmlx.dylib ./minilibx_macos/libmlx.dylib $(NAME)

$(OBJ) : $(HEADER)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MINILIB_DIR) clean
	rm -rf *.o

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all
