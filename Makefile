# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoudouy <acoudouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 15:39:04 by acoudouy          #+#    #+#              #
#    Updated: 2020/02/18 16:39:58 by acoudouy         ###   ########.fr        #
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

OBJ_PATH	= ./obj
OBJ_NAME	= $(SRC_NAME:.s=.o)

SRC 		= $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			= nasm


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJLIB)
	ar rc $(NAME) $(OBJ) $(OBJLIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -o $@ -f macho64 $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.s
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	$(CC) -o $@ -c $<

main: $(NAME)
	gcc -c src/main.c
	mv main.o obj
	gcc -o tester obj/main.o libasm.a

#mainbonus: bonus
#	gcc -c src/main_bonus.c
#	mv main_bonus.o obj
#	gcc -o tester_bonus obj/main_bonus.o $(OBJ)

clean:
	rm -rf $(OBJ) $(OBJLIB) obj/main.o

fclean: clean
	rm -rf ./obj $(NAME) obj/main.o
#	rm tester
#	rm $(NAME)

re: fclean all
