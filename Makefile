NAME	=	minishell
CFLAGS	=	-Wall -Werror -Wextra
SRC		=	minishell.c ms_loop.c builtin_cd.c env_funcs.c \
			builtin_exit.c builtin_echo.c builtin_env.c \
			builtin_setenv.c builtin_unsetenv.c utils.c execute.c
OBJ		=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@echo "Compiling $(NAME)"
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft

debug: $(OBJ)
	@make -C libft/
	@echo "Compiling $(NAME)"
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -g -fsanitize=address

clean:
	@echo "Removing Object Files..."
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "Removing $(NAME)"
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all