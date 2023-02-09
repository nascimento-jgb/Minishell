/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/09 14:16:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_vars(char *dir, char *a)
{
	free(dir);
	free(a);
}

int	prompt(t_minishell *minishell)
{
	while (minishell->signalDetect)
	{
		ms_signals(minishell);
		minishell->currentDir = get_dir();
		if (!minishell->currentDir)
			return (1);
		minishell->promptLine = readline(minishell->currentDir);
		if (!minishell->promptLine)
		{
			free(minishell->currentDir);
			return (1);
		}
		// if (fork_create() == 0)
		// 	run_command(parse_command(minishell->promptLine));
		// wait(NULL);
		add_history(minishell->promptLine);
		free_vars(minishell->currentDir, minishell->promptLine);
	}
	return (0);
}
