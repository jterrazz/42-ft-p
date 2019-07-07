# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 18:00:29 by jterrazz          #+#    #+#              #
#    Updated: 2019/07/07 12:31:34 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = inc
LIB_PATH = libs
BUILD_PATH = obj
SRC_PATH = src

SOURCES += server/main.c
SOURCES2 += client/main.c

LIB_SOURCES = $(LIB_PATH)/libft/libft.a

OBJECTS = $(SOURCES:%.c=$(BUILD_PATH)/%.o)
OBJECTS2 = $(SOURCES2:%.c=$(BUILD_PATH)/%.o)

# **************************************************************************** #
# VARIABLES         														   #
# **************************************************************************** #

NAME = serveur
NAME2 = client

CC = gcc
FLAGS_CC = -Wall -Wextra -Werror

# **************************************************************************** #
# COMMANDS  		    													   #
# **************************************************************************** #

.PHONY: all libs clean fclean re test

all: $(NAME) $(NAME2)

$(NAME): libs $(OBJECTS)
	$(CC) $(FLAGS_CC) -o $@ $(OBJECTS) $(LIB_SOURCES)

$(NAME2): $(OBJECTS2)
	$(CC) $(FLAGS_CC) -o $@ $(OBJECTS2) $(LIB_SOURCES)

$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS_CC) -c -o $@ $< -I $(INC_PATH)

libs:
	@make -s -C $(LIB_PATH)/libft

clean:
	@make clean -C $(LIB_PATH)/libft
	@rm -rf $(BUILD_PATH)
	@echo "Clean \033[33mok\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)/libft
	@rm -f $(NAME1) $(NAME2) $(LIB_NAME)
	@echo "Fclean \033[33mok\033[0m"

re: fclean $(NAME)
