# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <jterrazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/23 18:00:29 by jterrazz          #+#    #+#              #
#    Updated: 2019/07/30 19:58:24 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = inc
LIB_PATH = libs
BUILD_PATH = obj
SRC_PATH = src

SOURCES_C += client/main.c client/client.c client/interface.c
SOURCES_S += server/main.c

SHARED_SOURCES = shared/socket.c shared/cmd.c shared/ft_strjoin_free.c shared/parse.c shared/receive.c shared/send.c shared/stringify.c
SHARED_SOURCES += shared/cmd_handler/default.c shared/cmd_handler/ls.c shared/cmd_handler/get.c

SOURCES_C += $(SHARED_SOURCES)
SOURCES_S += $(SHARED_SOURCES)

LIBS = $(LIB_PATH)/libft/libft.a $(LIB_PATH)/ft_printf/libftprintf.a

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
	@make -s -C $(LIB_PATH)/ft_printf

clean:
	@make clean -C $(LIB_PATH)/libft
	@rm -rf $(BUILD_PATH)
	@echo "Clean \033[33mok\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)/libft
	@rm -f $(NAME_S) $(NAME_C) $(LIB_NAME)
	@echo "Fclean \033[33mok\033[0m"

re: fclean $(NAME)
