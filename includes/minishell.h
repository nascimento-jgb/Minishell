/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 15:21:45 by andrferr         ###   ########.fr       */
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
# include "defines.h"

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
void		ms_signals(t_minishell *minishell);


//parsing
int			check_tokken(char *scan);
int			skip_to_tokken(char **ptr_scan, char *end_scan, char *tokken);
int			get_tokken(char **ptr_scan, char *end_scan, char **tkn, char **end_tkn);
t_command	*parse_exec(char **ptr_scan, char *end_scan);

//parsing utils
t_command	*parse_command(char *scan);
t_command	*parse_line(char **ptr_scan, char *end_scan);
int			check_tokken(char *scan);
int			skip_to_tokken(char **ptr_scan, char *end_scan, char *tokken);
int			get_tokken(char **ptr_scan, char *end_scan, char **tkn, char **end_tkn);
t_command	*null_terminate(t_command *cmd);
void		run_command(t_command *cmd);
void		run_pipe(t_pipecmd *pipe_cmd, t_command *cmd, int p[]);
void		run_redirect(t_redirectcmd	*redir_cmd, t_command *cmd);
void		run_andoperator(t_andcmd *and_operator, t_command *cmd);
void		run_exec(t_execcmd *exec_cmd, t_command *cmd);
int			fork_create(void);
#endif
