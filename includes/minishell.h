/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 11:24:56 by jonascim         ###   ########.fr       */
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

# define PIPE			1
# define REDIRECT		2
# define EXEC			3
// # define QUOTATION	4
// # define INTERACTIVE	5
// # define DOLLARSIGN	6
// # define BUILTIN		7 (echo, cd, pwd, export, unset, env, exit)
# define OPERATORAND	8 //(&&)
// # define OPERATOROR  9 (||)
// # define WILDCARD	0 (*)
# define MAXARGS 		10


typedef struct	s_command
{
	int	command_type;
}	t_command;

typedef struct	s_pipecmd
{
	int			type;
	t_command	*left;
	t_command	*right;
}	t_pipecmd;

typedef struct	s_redirectcmd
{
	int			type;
	char		*file;
	char		*exit_file;
	int			mode;
	int			fd;
	t_command	*cmd;
}	t_redirectcmd;

typedef struct s_execcmd
{
	int		type;
	char	*argv[MAXARGS];
	char	*eargv[MAXARGS];
}	t_execcmd;

typedef struct	s_andcmd
{
	int			type;
	t_command	*cmd;
}	t_andcmd;
# include <string.h>
# include "structs.h"

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

//parsing
int		check_tokken(char *scan);
int		skip_to_tokken(char **ptr_scan, char *end_scan, char *tokken);
int		get_tokken(char **ptr_scan, char *end_scan, char **tkn, char **end_tkn);
//parsing utils

#endif
