/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minienv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OMI <mcharouh@student.1337.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:05:08 by OMI               #+#    #+#             */
/*   Updated: 2023/02/16 22:28:40 by OMI              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIENV_H
# define MINIENV_H

typedef struct s_env
{
	char			*key_pair;
	struct s_env	*next;
}				t_env;

t_env		*init_minienv(char **envp);
t_env		*minienv_node(char *name, t_env *minienv);
char		*minienv_value(char *name, t_env *minienv);
void		minienv_update(char *name, char *value, t_env *minienv);
void		list_append(char *key_pair, t_env **list);
char		**minienv_to_envp(t_env *minienv);
void		free_minienv(t_env **minienv);
char		*create_keypair(char *name, char *value);
char		*name_only(char *key_pair);
char		*value_only(char *key_pair);
void		minienv_var_update(char *name, char *value, t_env *minienv);
size_t		minienv_size(t_env *minienv);

#endif
