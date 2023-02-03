/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/03 11:26:07 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PIPE			1
# define REDIRECT		2
// # define EXEC		3
// # define QUOTATION	4
// # define INTERACTIVE	5
// # define DOLLARSIGN	6
// # define BUILTIN		7 (echo, cd, pwd, export, unset, env, exit)
// # define OPERATOR	8 ( || and && )
// # define WILDCARD	9 ( * )



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

void	exit_message(char *error);
void	open_shell(void);
char	*get_dir(void);
int		prompt(void);

//parsing
int		check_tokken(char *scan);
int		skip_to_tokken(char **ptr_scan, char *end_scan, char *tokken);
int		get_tokken(char **ptr_scan, char *end_scan, char **tkn, char **end_tkn);
//parsing utils

#endif
