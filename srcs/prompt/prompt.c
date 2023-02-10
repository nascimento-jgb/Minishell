/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/10 16:18:56 by andrferr         ###   ########.fr       */
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
	while (1)
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
		get_argc_argv(minishell, minishell->promptLine);
		if (fork_create() == 0)
			run_command(parse_command(minishell->promptLine));
		wait(NULL);
		add_history(minishell->promptLine);
		free_vars(minishell);
	}
	return (0);
}
