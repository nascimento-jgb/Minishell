/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 13:01:37 by andrferr         ###   ########.fr       */
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

void		exit_message(char *error);
void		open_shell(void);
char		*get_dir(void);
int			prompt(t_minishell *minishell);
void		blt_error_msg(char *cmd, int err, char *path);
void		ms_cd(char *path);
void		ms_pwd(void);
void		ms_echo(char *message, int	flag);
void		ms_env(t_list *env);
int			ms_exit(int error_code);
t_minishell	*minishell_init(int argc, char **argv, char **env);
t_env		*env_init(char **env);
void		clean_minishell(t_minishell *minishell);
t_vars		*vars_init(void);
int			ms_export(t_minishell *minishell, char *path);
int			unset(t_minishell *minishell, char *var);

#endif
