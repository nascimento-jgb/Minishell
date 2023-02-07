/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:44:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 15:22:17 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "defines.h"

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
