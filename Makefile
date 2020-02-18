# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoudouy <acoudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 15:39:04 by acoudouy          #+#    #+#              #
#    Updated: 2020/02/18 15:55:17 by acoudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   cub3D
INC			=   ./include
SRC_PATH 	=   ./src
SRC_NAME 	=	ft_read.s			\
				ft_strcmp.s			\
				ft_strcpy.s			\
				ft_strdup.s			\
				ft_strlen.s			\
				ft_write.s

OBJ_PATH	= ./obj
OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC 		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			= nasm

all: $(NAME)

$(FLAG):	-f macho64

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o ${NAME} ${OBJ}

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

clean:		
			rm -f $(OBJ)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		clean fclean all re

