/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/06 18:05:29 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include "structs.h"
# include <signal.h>

void		exit_message(char *error);
void		open_shell(void);
char		*get_dir(void);
int			prompt(t_minishell *minishell);
void		blt_error_msg(char *cmd, int err, char *path);
void		ms_cd(char *path);
void		ms_pwd(void);
void		ms_echo(char *message, int flag);
void		ms_env(t_vars *env);
int			ms_exit(int error_code);
t_minishell	*minishell_init(int argc, char **argv, char **env);
t_env		*env_init(char **env);
void		clean_minishell(t_minishell *minishell);
int			ms_export(t_minishell *minishell, char *path);
int			ms_unset(t_minishell *minishell, char *var);
t_vars		*vars_new(char *var);
void		vars_addback(t_vars **list, t_vars *node);
void		vars_listclear(t_vars **list);
void		vars_delnode(t_vars *node);
void		vars_remove_node(t_vars **list, t_vars *node);
void		ms_signals();

#endif
