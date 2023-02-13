/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/13 09:39:07 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*pipe_cmd_init(t_command *left_param, t_command *right_param)
{
	t_pipecmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		exit_message("Error.\n");
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left_param;
	cmd->right = right_param;
	return ((t_command *)cmd);
}

t_command	*redirect_cmd_init(t_command *subcmd, char *file, char *exit_file, int mode, int fd)
{
	t_redirectcmd *cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		exit_message("Error.\n");
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = REDIRECT;
	cmd->cmd = subcmd;
	cmd->file = file;
	cmd->exit_file = exit_file;
	cmd->mode = mode;
	cmd->fd = fd;
	return ((t_command *)cmd);
}

t_command	*exec_cmd_init(void)
{
	t_execcmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = EXEC;
	return ((t_command *)cmd);
}

t_command	*and_cmd_init(t_command *subcmd)
{
	t_andcmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = OPERATORAND;
	cmd->cmd = subcmd;
	return ((t_command *)cmd);
}

t_command	*line_cmd_init(t_command *left, t_command *right)
{
	t_linecmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = LINE;
	cmd->left = left;
	cmd->right = right;
	return ((t_command *)cmd);
}
