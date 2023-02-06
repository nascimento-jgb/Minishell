/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_terminate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:24:26 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/06 09:37:12 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_command *null_terminate(t_command *cmd)
{
	t_execcmd		*exec_cmd;
	t_pipecmd		*pipe_cmd;
	t_redirectcmd	*redir_cmd;
	t_andcmd		*and_cmd;
	int				i;

	i = 0;
	if (cmd == 0)
		return (0);
	if (cmd->command_type == PIPE)
	{
		pipe_cmd = (t_pipecmd *)cmd;
		null_terminate(pipe_cmd->left);
		null_terminate(pipe_cmd->right);
	}
	else if (cmd->command_type == REDIRECT)
	{
		redir_cmd = (t_redirectcmd *)cmd;
		null_terminate(redir_cmd->cmd);
		*redir_cmd->exit_file = 0;
	}
	else if (cmd->command_type == EXEC)
	{
		while (exec_cmd->argv[i])
			exec_cmd->eargv[i++] = 0;
	}
	else if (cmd->command_type == OPERATORAND)
	{
		and_cmd = (t_andcmd *)cmd;
		null_terminate(and_cmd->cmd);
	}
	return (cmd);
}
