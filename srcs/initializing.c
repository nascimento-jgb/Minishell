/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/27 15:47:39 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_command *pipe_command(t_command *left_param, t_command *right_param)
{
	t_pipecmd *cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		exit_message("Error.\n"); // doube check if exit can be done at this point of the program
	memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left_param;
	cmd->right = right_param;
	return ((struct t_command *)cmd);
}
