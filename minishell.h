/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:05:44 by OMI               #+#    #+#             */
/*   Updated: 2023/02/17 01:59:50 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED	"\001\e[0;31m\002"
# define WHT	"\001\e[0;37m\002"
# define CRESET	"\001\e[0m\002"

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILED 0
# define PATH_MAX	4096
# define LLONG_MAX 9223372036854775807

# define NO_REDIRECT -1

# include "includes/allowed_libs.h"
# include "includes/errors.h"
# include "includes/minienv.h"
# include "includes/builtins.h"
# include "includes/executes.h"

int			minishell(t_env	*minienv);
char		*prompt_input(t_env *minienv);
int			has_input_error(char *input, int *exit_status, t_env *minienv);
int			has_unclosed_quotes(char *str);
int			is_invalid_syntax(char *input);
int			is_invalid_token(char c);
int			unexpected_token(char *input);
int			syntax_error(char *token);
char		*get_next_pipe(char *str);
int			handle_heredoc(char *input, int *exit_status, t_env *minienv);
void		handle_expansions(char **input, t_env *minienv, int exit_status);
void		expand_variables(char **input, t_env *minienv);
void		expand_exit_status(char **input, int exit_status);
char		**split_commands(char *input);
char		**split_args(char *command);
void		define_main_signals(void);
void		define_execute_signals(int child_pid);
void		define_heredoc_signals(int child_pid);
int			str_equal(const char *str1, const char *str2);
int			is_quote(char c);
int			is_empty(char *str);
int			is_name_delimeter(char c);
int			has_pipe(char *str);
void		free_array(char **arr);
int			arr_len(char **arr);
long long	ft_atoll(const char *str);
void		move_one_forward(char *str);
char		*get_token_position(char *str, char *token);
int			skip_quotes(char *str);

#endif
