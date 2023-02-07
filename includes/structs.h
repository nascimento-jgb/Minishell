/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:44:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 13:28:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vars
{
	char			*key;
	char			*value;
	char			*path;
	struct s_vars	*next;
}	t_vars;

typedef struct s_env
{
	t_vars	*vars_list;
	int		total_env_vars;
}	t_env;

typedef struct s_minishell
{
	t_env	*env;
	int		argc;
	char	**argv;
	char	*promptLine;
	int		signalDetect;
}	t_minishell;

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
	int					type;
	struct s_command	*left;
	struct s_command	*right;
}	t_pipecmd;

typedef struct	s_redirectcmd
{
	int					type;
	char				*file;
	char				*exit_file;
	int					mode;
	int					fd;
	struct s_command	*cmd;
}	t_redirectcmd;

typedef struct s_execcmd
{
	int		type;
	char	*argv[MAXARGS];
	char	*eargv[MAXARGS];
}	t_execcmd;

typedef struct	s_andcmd
{
	int					type;
	struct s_command	*cmd;
}	t_andcmd;

#endif
