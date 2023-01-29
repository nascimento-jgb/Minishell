/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:00:09 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 15:48:17 by jonascim         ###   ########.fr       */
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

# define PIPE	1
// # define REDIR	2
// # define EXEC	3
// # define LIST	4
// # define EXTRA	5
// # define BUILTIN	6

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

typedef struct	s_pipecmd
{
	int		type;
	char	*str;
	struct t_command	*left;
	struct t_command	*right;
}	t_pipecmd;

void	exit_message(char *error);
void	open_shell(void);
char	*get_dir(void);
int		prompt(void);

#endif
