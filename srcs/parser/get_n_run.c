/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:14 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/10 16:44:18 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_command(t_command *cmd, t_minishell *minishell)
{
	t_pipecmd		*pipe_cmd = NULL;
	t_redirectcmd	*redir_cmd = NULL;
	t_andcmd		*and_operator = NULL;
	t_execcmd		*exec_cmd = NULL;
	t_linecmd		*line_cmd = NULL;
	int				p[2];

	if (cmd == 0)
		exit(1);
	else if (cmd->command_type == PIPE)
		run_pipe(pipe_cmd, cmd, p, minishell);
	else if (cmd->command_type == REDIRECT)
		run_redirect(redir_cmd, cmd, minishell);
	else if (cmd->command_type == OPERATORAND)
		run_andoperator(and_operator, cmd, minishell);
	else if (cmd->command_type == EXEC)
		run_exec(exec_cmd, cmd, minishell);
	else if (cmd->command_type == LINE)
		run_line(line_cmd, cmd, minishell);
	else
		exit_message("run_command() Error.\n");
}
