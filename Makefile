# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoudouy <acoudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 15:39:04 by acoudouy          #+#    #+#              #
#    Updated: 2020/02/19 15:03:28 by acoudouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   libasm.a
INC			=   ./include
SRC_PATH 	=   ./src
SRC_NAME 	=	ft_read.s			\
				ft_strcmp.s			\
				ft_strcpy.s			\
				ft_strdup.s			\
				ft_strlen.s			\
				ft_write.s

SRC_NAME_B  = 	ft_list_size_bonus.s	\
				ft_list_push_front_bonus.s

OBJ_PATH	= ./obj
OBJ_B_PATH	= ./obj
OBJ_NAME	= $(SRC_NAME:.s=.o)
OBJ_NAME_B	= $(SRC_NAME_B:.s=.o)

SRC 		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC_B 		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_B 		= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_B))

CC			= nasm
FLAG		= -f macho64

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $(OBJ) $(OBJ_B)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ $(FLAG) $<

$(OBJ_B_PATH)/%.o: $(SRC_PATH)/%.s
	@mkdir $(OBJ_B_PATH) 2> /dev/null || true
	$(CC) -o $@ $(FLAG) $<

test: bonus ./test
	@cp ./test/test.c .
	@gcc -c test.c
	@rm test.c
	gcc $(NAME) test.o
	@rm test.o

clean:
	rm -rf $(OBJ) $(OBJ_B) obj/main.o

fclean: clean
	rm -rf ./obj $(NAME)
	rm -rf a.out

re: fclean all
