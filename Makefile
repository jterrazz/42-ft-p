# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 18:00:29 by jterrazz          #+#    #+#              #
#    Updated: 2019/07/28 01:13:16 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = inc
LIB_PATH = libs
BUILD_PATH = obj
SRC_PATH = src

SOURCES_C += client/main.c
SOURCES_S += server/main.c

LIBS = $(LIB_PATH)/libft/libft.a

OBJECTS_S = $(SOURCES_S:%.c=$(BUILD_PATH)/%.o)
OBJECTS_C = $(SOURCES_C:%.c=$(BUILD_PATH)/%.o)

# **************************************************************************** #
# VARIABLES         														   #
# **************************************************************************** #

NAME = ft_p
NAME_S = serveur
NAME_C = client

CC = gcc
FLAGS_CC = -Wall -Wextra -Werror

# **************************************************************************** #
# COMMANDS  		    													   #
# **************************************************************************** #

.PHONY: all libs clean fclean re

all: $(NAME)

$(NAME): $(NAME_S) $(NAME_C)

$(NAME_S): libs $(OBJECTS_S)
	$(CC) $(FLAGS_CC) -o $@ $(OBJECTS_S) $(LIBS)

$(NAME_C): $(OBJECTS_C)
	$(CC) $(FLAGS_CC) -o $@ $(OBJECTS_C) $(LIBS)

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
	@rm -f $(NAME_S) $(NAME_C) $(LIB_NAME)
	@echo "Fclean \033[33mok\033[0m"

re: fclean $(NAME)
