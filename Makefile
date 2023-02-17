SRC = main.c\
		builtins/cd.c\
		builtins/export.c\
		builtins/env.c\
		builtins/unset.c\
		builtins/pwd.c\
		builtins/echo.c\
		builtins/exit.c\
		builtins/builtins_utils.c\
		executes/execute_builtin.c\
		executes/execute_external.c\
		executes/execute_multiple_commands.c\
		executes/execute_one_command.c\
		executes/get_path.c\
		executes/multiple_commands_utils.c\
		executes/one_command_utils.c\
		executes/pipes.c\
		executes/split_args.c\
		executes/wait.c\
		expansions/expand_exit_status.c\
		expansions/expand_variables.c\
		minienv/free_minienv.c\
		minienv/minienv_str_utils.c\
		minienv/minienv_utils.c\
		minienv/minienv.c\
		redirects/redirect_heredoc.c\
		redirects/redirect_input.c\
		redirects/redirect_output.c\
		redirects/redirect_utils.c\
		src/handle_heredoc.c\
		src/input_error.c\
		src/minishell.c\
		src/prompt.c\
		src/split_commands.c\
		utils/arr_len.c\
		utils/error.c\
		utils/file_descriptors.c\
		utils/free_array.c\
		utils/ft_atoll.c\
		utils/get_label_name.c\
		utils/quote_checker.c\
		utils/signals.c\
		utils/skip_quotes.c\
		utils/str_checkers.c\
		utils/str_utils.c\
		syntax/syntax_utils.c\
		syntax/syntax.c

FLAGS = -Wall -Wextra -Werror

NAME = minishell

all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(FLAGS) $(SRC) libft/libft.a -o $(NAME) -lreadline -L/Users/mcharouh/homebrew/opt/readline/lib -I/Users/mcharouh/homebrew/opt/readline/include
clean :
	@rm -rf $(NAME)
	
fclean : clean

re : fclean all
