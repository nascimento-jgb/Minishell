/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/10 13:36:35 by jonascim         ###   ########.fr       */
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
		minishell->capturedLine = readline(dir);
		if (!minishell->capturedLine)
		{
			free(dir);
			return (1);
		}
		if (fork_create() == 0)
			run_command(parse_command(minishell->capturedLine));
		wait(NULL);
		add_history(minishell->capturedLine);
		free_vars(dir, minishell->capturedLine);
	}
	return (0);
}
