/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:14 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/29 21:55:14 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// insert here function get command
int	get_command()
{

}


void	run_command(t_command *cmd)
{
	t_pipecmd		*pipe_cmd;
	t_redirectcmd	*redir_cmd;
	int			p[2];

	if (cmd == 0)
		exit();
	else if (cmd->command_type == PIPE)
		run_pipe(pipe_cmd, cmd, p);
	else if (cmd->command_type == REDIR)
		run_redirect(redir_cmd, cmd);
	else
		exit_message("run_command() Error.\n");
}
