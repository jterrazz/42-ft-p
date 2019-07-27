cmake_minimum_required(VERSION 3.14)
project(42_ft_p C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)
include_directories(libs/get_next_line)
include_directories(libs/libft)
include_directories(src)

add_executable(42_ft_p
		src/client/main.c
		libs/get_next_line/get_next_line.c
        libs/get_next_line/get_next_line.h
        libs/libft/ft_atoi.c
        libs/libft/ft_bzero.c
        libs/libft/ft_isalnum.c
        libs/libft/ft_isalpha.c
        libs/libft/ft_isascii.c
        libs/libft/ft_isdigit.c
        libs/libft/ft_isprint.c
        libs/libft/ft_itoa.c
        libs/libft/ft_lstadd.c
        libs/libft/ft_lstdel.c
        libs/libft/ft_lstdelone.c
        libs/libft/ft_lstiter.c
        libs/libft/ft_lstmap.c
        libs/libft/ft_lstnew.c
        libs/libft/ft_memalloc.c
        libs/libft/ft_memccpy.c
        libs/libft/ft_memchr.c
        libs/libft/ft_memcmp.c
        libs/libft/ft_memcpy.c
        libs/libft/ft_memdel.c
        libs/libft/ft_memmove.c
        libs/libft/ft_memset.c
        libs/libft/ft_putchar.c
        libs/libft/ft_putchar_fd.c
        libs/libft/ft_putendl.c
        libs/libft/ft_putendl_fd.c
        libs/libft/ft_putnbr.c
        libs/libft/ft_putnbr_fd.c
        libs/libft/ft_putstr.c
        libs/libft/ft_putstr_fd.c
        libs/libft/ft_strcat.c
        libs/libft/ft_strchr.c
        libs/libft/ft_strclr.c
        libs/libft/ft_strcmp.c
        libs/libft/ft_strcpy.c
        libs/libft/ft_strdel.c
        libs/libft/ft_strdup.c
        libs/libft/ft_strequ.c
        libs/libft/ft_striter.c
        libs/libft/ft_striteri.c
        libs/libft/ft_strjoin.c
        libs/libft/ft_strlcat.c
        libs/libft/ft_strlen.c
        libs/libft/ft_strmap.c
        libs/libft/ft_strmapi.c
        libs/libft/ft_strncat.c
        libs/libft/ft_strncmp.c
        libs/libft/ft_strncpy.c
        libs/libft/ft_strnequ.c
        libs/libft/ft_strnew.c
        libs/libft/ft_strnstr.c
        libs/libft/ft_strrchr.c
        libs/libft/ft_strsplit.c
        libs/libft/ft_strstr.c
        libs/libft/ft_strsub.c
        libs/libft/ft_strtrim.c
        libs/libft/ft_tolower.c
        libs/libft/ft_toupper.c
        libs/libft/libft.h
	src/ft_p.h src/server/main.c)
