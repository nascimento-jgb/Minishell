/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/29 21:55:17 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	wait();
	wait();
}

void	run_redirect(t_redirectcmd	*redir_cmd, t_command *cmd)
{
	redir_cmd = (t_redirectcmd *)cmd;
	close(redir_cmd->fd);
	if (open(redir_cmd-> file, redir_cmd->mode) < 0)
		exit("Filed to open file.\n");
	run_command(redir_cmd->cmd);
}
