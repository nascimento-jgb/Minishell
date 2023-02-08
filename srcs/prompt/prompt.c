/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/08 09:13:27 by jonascim         ###   ########.fr       */
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
	char	*dir;

	while (minishell->signalDetect)
	{
		ms_signals(minishell);
		dir = get_dir();
		if (!dir)
			return (1);
		minishell->promptLine = readline(dir);
		if (!minishell->promptLine)
		{
			free(dir);
			return (1);
		}
		if (fork_create() == 0)
			run_command(parse_command(minishell->promptLine));
		wait(NULL);
		add_history(minishell->promptLine);
		free_vars(dir, minishell->promptLine);
	}
	return (0);
}
