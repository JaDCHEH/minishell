# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 18:25:04 by cjad              #+#    #+#              #
#    Updated: 2022/05/27 11:46:54 by cjad             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = ./libft/libft.a

CC = @cc

FLAGS = -Wall -Wextra -Werror -lreadline -L/Users/cjad/goinfre/brew/opt/readline/lib -I/Users/cjad/goinfre/brew/opt/readline/include

RM = @rm -f

OBJS =	./libft/ft_itoa.o\
		./libft/ft_atoi.o \
		./libft/ft_bzero.o \
		./libft/ft_split.o  \
		./libft/ft_memchr.o  \
		./libft/ft_strlen.o   \
		./libft/ft_memset.o    \
		./libft/ft_calloc.o     \
		./libft/ft_memcpy.o      \
		./libft/ft_strchr.o       \
		./libft/ft_memcmp.o        \
		./libft/ft_strdup.o         \
		./libft/ft_substr.o          \
		./libft/ft_isalpha.o          \
		./libft/ft_isdigit.o           \
		./libft/ft_isalnum.o            \
		./libft/ft_isascii.o             \
		./libft/ft_isprint.o              \
		./libft/ft_memmove.o               \
		./libft/ft_strlcpy.o                \
		./libft/ft_strlcat.o                 \
		./libft/ft_toupper.o                  \
		./libft/ft_tolower.o                   \
		./libft/ft_strrchr.o                    \
		./libft/ft_strncmp.o                     \
		./libft/ft_strcmp.o                       \
		./libft/ft_strnstr.o                       \
		./libft/ft_strjoin.o                        \
		./libft/ft_strtrim.o                         \
		./libft/ft_strmapi.o                          \
		./libft/ft_striteri.o                          \
		./libft/ft_putnbr_fd.o                          \
		./libft/ft_putstr_fd.o                           \
		./libft/ft_putchar_fd.o                           \
		./libft/ft_putendl_fd.o

C_FILES =	minishell.c        \
			execution/pipe.c    \
			execution/id_utils.c \
			execution/execution.c \
			execution/find_path.c  \
			execution/execute.c     \
			execution/execute_utils.c\
			built-ins/echo.c          \
			built-ins/ft_cd.c   	   \
			built-ins/b_sort.c   	    \
			built-ins/ft_pwd.c    		 \
			built-ins/ft_env.c    		  \
			built-ins/ft_unset.c  		   \
			built-ins/ft_export.c   	    \
			built-ins/mini_utils.c   	     \
			built-ins/ft_cd_utils.c    		  \
			built-ins/ft_lstadd_back.c    	   \
			built-ins/ft_export_utils.c    	    \
			parsing/parsing.c          		     \
		 	parsing/lexer.c            		      \
			parsing/lexer_utils1.c                 \
			parsing/lexer_utils2.c                  \
			parsing/lexer_utils3.c                   \
			parsing/lexer_utils4.c                    \
			parsing/parsing_utils1.c                   \
			parsing/parsing_utils2.c                    \
			parsing/parsing_utils3.c                     \
			parsing/parsing_check.c                       \
			parsing/get_next_line.c

N_FLAG = -o

#  colors

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all :  $(LIBFT) $(NAME)

$(NAME) : $(LIBFT) $(C_FILES) 
	@echo "$(C_GREEN)["minishell" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(LIBFT) $(N_FLAG) $(NAME)

$(LIBFT) : $(OBJS)
	@echo "$(C_GREEN)["libft.a" CREATED]$(C_RES)"
	@make -C ./libft

clean :
	@echo "$(C_L_BLUE)[OBJECTS REMOVED]$(C_RES)"
	@make clean -C ./libft

fclean : clean
	@echo "$(C_RED)["minishell and libtf.a" REMOVED]$(C_RES)"
	@make fclean -C ./libft
	$(RM) $(NAME)

re : fclean all