/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/08 12:39:18 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_pipe(t_pipecmd *pipe_cmd, t_command *cmd, int p[])
{
	pipe_cmd = (t_pipecmd *)cmd;
	if (pipe(p) < 0)
		exit_message("Error.\n");
	if (fork_create() == 0)
	{
		close(1);
		dup(p[1]);
		close(p[0]);
		close(p[1]);
		run_command(pipe_cmd->left);
	}
	if (fork_create() == 0)
	{
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		run_command(pipe_cmd->right);
	}
	close(p[0]);
	close(p[1]);
	wait(NULL);
	wait(NULL);
}

void	run_redirect(t_redirectcmd	*redir_cmd, t_command *cmd)
{
	redir_cmd = (t_redirectcmd *)cmd;
	close(redir_cmd->fd);
	if (open(redir_cmd->file, redir_cmd->mode) < 0)
		exit_message("Filed to open file.\n");
	run_command(redir_cmd->cmd);
}

void	run_andoperator(t_andcmd *and_operator, t_command *cmd)
{
	and_operator = (t_andcmd *)cmd;
	if (fork_create() == 0)
		run_command(and_operator->cmd);
}

void	run_exec(t_execcmd *exec_cmd, t_command *cmd)
{
	exec_cmd = (t_execcmd *)cmd;
	if (exec_cmd->argv[0] == 0)
		exit(1);
	execv(exec_cmd->argv[0], exec_cmd->argv);
	exit_message("exec() failed\n");
}
