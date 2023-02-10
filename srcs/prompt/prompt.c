/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/10 13:36:35 by jonascim         ###   ########.fr       */
=======
/*   Updated: 2023/02/09 17:23:49 by andrferr         ###   ########.fr       */
>>>>>>> 665b83fdc226a9449b83fa192a8fdc8cad9fb303
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_vars(t_minishell *minishell)
{
	int i;

	free(minishell->currentDir);
	free(minishell->promptLine);
	i = 0;
	while (minishell->argv[i])
		ft_strdel(&minishell->argv[i++]);
	free(minishell->argv);
	minishell->argc = 0;
}

static void	get_argc_argv(t_minishell *minishell ,char *str)
{
	int	i;

	minishell->argv = ft_split(str, ' ');
	i = 0;
	while (minishell->argv[i])
		i++;
	minishell->argc = i;
}

int	prompt(t_minishell *minishell)
{
	while (minishell->signalDetect)
	{
		ms_signals(minishell);
		minishell->currentDir = get_dir();
		if (!minishell->currentDir)
			return (1);
<<<<<<< HEAD
		minishell->capturedLine = readline(dir);
		if (!minishell->capturedLine)
=======
		minishell->promptLine = readline(minishell->currentDir);
		if (!minishell->promptLine)
>>>>>>> 665b83fdc226a9449b83fa192a8fdc8cad9fb303
		{
			free(minishell->currentDir);
			return (1);
		}
		get_argc_argv(minishell, minishell->promptLine);
		if (fork_create() == 0)
			run_command(parse_command(minishell->capturedLine));
		wait(NULL);
<<<<<<< HEAD
		add_history(minishell->capturedLine);
		free_vars(dir, minishell->capturedLine);
=======
		add_history(minishell->promptLine);
		free_vars(minishell);
>>>>>>> 665b83fdc226a9449b83fa192a8fdc8cad9fb303
	}
	return (0);
}
