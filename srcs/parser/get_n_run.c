/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:14 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/08 09:53:52 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_command(t_command *cmd)
{
	t_pipecmd		*pipe_cmd = NULL;
	t_redirectcmd	*redir_cmd = NULL;
	t_andcmd		*and_operator = NULL;
	t_execcmd		*exec_cmd = NULL;
	int				p[2];

	if (cmd == 0)
		exit(1);
	else if (cmd->command_type == PIPE)
		run_pipe(pipe_cmd, cmd, p);
	else if (cmd->command_type == REDIRECT)
		run_redirect(redir_cmd, cmd);
	else if (cmd->command_type == OPERATORAND)
		run_andoperator(and_operator, cmd);
	else if (cmd->command_type == EXEC)
		run_exec(exec_cmd, cmd);
	else
		exit_message("run_command() Error.\n");
}