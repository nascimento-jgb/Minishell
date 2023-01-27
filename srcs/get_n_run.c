/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:14 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/27 15:47:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// insert here function get command

int	get_command()
{

}


void	run_command(t_command *cmd)
{
	t_pipecmd	*pipe_cmd;
	int					p[2];

	if (cmd == 0)
		exit();
	else if (cmd->type == PIPE)
		run_pipe(pipe_cmd, cmd, p);
	//else if (other cases)
	//else for default case
}
