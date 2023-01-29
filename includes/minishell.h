/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 21:55:31 by jonascim         ###   ########.fr       */
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
	int					type;
	struct t_command	*left;
	struct t_command	*right;
}	t_pipecmd;

typedef struct	s_redirectcmd
{
	int		type;
	char	*file;
	char	*exit_file;
	int		mode;
	int		fd;
	struct t_command *cmd;
}	t_redirectcmd;

void	exit_message(char *error);
void	open_shell(void);
char	*get_dir(void);
int		prompt(void);

#endif
