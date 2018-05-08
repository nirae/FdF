# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndubouil <ndubouil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:28:24 by ndubouil          #+#    #+#              #
#    Updated: 2018/05/08 18:19:07 by ndubouil         ###   ########.fr        #
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
LIBFT	=	./libft/
ILIBFT	=	./$(LIBFT)includes/
MLX		=	./mlx/
H		=	./includes/
SRC		=	./src/
#  Files
HFILES	=	$(H)fdf.h
MAIN	=	main.c
SRCS	=	$(SRC)fill_pixel.c		\
			$(SRC)fill_segment.c	\
			$(SRC)get_height.c		\
			$(SRC)get_width.c		\
			$(SRC)if_width_valid.c	\
			$(SRC)parser.c			\
			$(SRC)make_array.c		\
			$(SRC)create_pixel.c	\
			$(SRC)start_points.c	\
			$(SRC)set_or_to_curr.c	\
			$(SRC)zoom.c			\
			$(SRC)projections.c		\
			$(SRC)fill_square.c		\
			$(SRC)menu.c			\
			$(SRC)set_color.c		\
			$(SRC)errors.c			\
			$(SRC)free_env.c		\
			$(SRC)quit.c
OBJ		=	$(patsubst %.c,%.o,$(SRCS))
# Name
NAME	=	fdf

.PHONY: all clean fclean re

all:		$(NAME)
		@true

$(NAME):	$(OBJ) $(MAIN) $(H) $(MLX) $(LIBFT) Makefile
		@echo "Compiling MLX ..."
		@make -C $(MLX)
		@echo "Compiling Libft ..."
		@make -C $(LIBFT)
		@echo "Building $(NAME) ..."
		@$(CC) $(CFLAGS) $(MAIN) $(OBJ) -I$(H) -I$(MLX) -I$(ILIBFT) -L$(MLX) -lmlx -L$(LIBFT) -lft $(LFLAGS) -o $(NAME)
		@echo "I'm READY"

%.o: 		%.c
		@echo "Creating $@ ..."
		@$(CC) $(CFLAGS) -I$(H) -I$(MLX) -I$(ILIBFT) -c $< -o $@

clean:
		@echo "Cleaning Objs ..."
		@$(RM) -f $(OBJ)
		@echo "Cleaning MLX Objs ..."
		@make clean -C $(MLX)
		@echo "Cleaning Libft Objs ..."
		@make clean -C $(LIBFT)

fclean:		clean
		@echo "Cleaning $(NAME) exec"
		@$(RM) -f $(NAME)
		@echo "Cleaning libft exec"
		@make fclean -C $(LIBFT)

re:			fclean all
