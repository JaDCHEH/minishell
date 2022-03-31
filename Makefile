NAME = minishell

LIBFT = ./libft/libft.a

CC = @cc

FLAGS = -Wall -Wextra -Werror

RM = @rm -f

C_FILES = 	include/lexer.c \
			include/utils.c \


N_FLAG = -o

#  colors

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(LIBFT) $(C_FILES) 
	@echo "$(C_GREEN)["minishell" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(LIBFT) $(N_FLAG) $(NAME)

$(LIBFT) :
	@make -C ./libft
	@make clean -C ./libft

clean :
	@echo "$(C_RED)["libft.a" REMOVED]$(C_RES)"
	@make fclean -C ./libft

fclean : clean
	@echo "$(C_RED)["minishell and libtf.a" REMOVED]$(C_RES)"
	$(RM) $(NAME)

re : fclean all