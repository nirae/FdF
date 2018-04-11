# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:28:24 by ndubouil          #+#    #+#              #
#    Updated: 2018/04/11 22:21:49 by ndubouil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries and Flags
CC		=	/usr/bin/gcc
AR		=	/usr/bin/ar
RANLIB	=	/usr/bin/ranlib
RM		=	/bin/rm
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-framework OpenGL -framework Appkit
# Directories
# LIB		=	./libft/
MLX		=	./mlx/
H		=	./includes
#  Files
HFILES	=	$(H)/fdf.h
MAIN	=	main.c
SRC		=	fill_pixel.c
OBJ		=	$(patsubst %.c,%.o,$(SRC))
# Name
NAME	=	fdf

.PHONY: all clean fclean re

all:		$(NAME)
		@true

$(NAME):	$(OBJ) $(MAIN) $(HFILES) $(MLX) Makefile
		@echo "Compiling MLX ..."
		@make -C $(MLX)
		@echo "Building $(NAME) ..."
		@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -I$(H) -I$(MLX) -L$(MLX) -lmlx $(LFLAGS) -o $(NAME)
		@echo "I'm READY"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Cleaning Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning MLX Objs ..."
		@make clean -C $(MLX)

fclean:		clean
		@echo "Cleaning $(NAME) exec"
		@$(RM) -f $(NAME)
		#@echo "Cleaning libft exec"
		#@make fclean -C $(LIB)

re:			fclean all
