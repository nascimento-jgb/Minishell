/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 16:46:15 by andrferr         ###   ########.fr       */
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


typedef struct s_bash_vars
{
	char	**vars_arr;
}	t_bash_vars;

void	exit_message(char *error);
void	open_shell(void);
char	*get_dir(void);
int		prompt(int argc, char **argv, char **env);
void	blt_error_msg(char *cmd, int err, char *path);
void	ms_cd(char *path);
void	ms_pwd(void);
void	ms_echo(char *message, int	flag);
void	ms_env(char **env);
int		ms_exit(int error_code);

#endif
