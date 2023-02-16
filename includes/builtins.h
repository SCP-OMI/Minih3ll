/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:04:57 by OMI               #+#    #+#             */
/*   Updated: 2023/02/16 22:52:59 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minienv.h"

int	is_builtin(char *command);
int	cd(char **args, t_env *minienv);
int	echo(char **args);
int	pwd(void);
int	builtin_export(char **args, t_env **minienv);
int	env(t_env *envp);
int	unset(char **args, t_env **minienv);
int	builtin_exit(char **args);

// utils
int	is_varname(char c);
int	is_valid_varname(char *name);

//10
#endif
