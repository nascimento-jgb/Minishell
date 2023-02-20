/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/20 13:05:22 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_vars(t_minishell *minishell)
{
	int i;

	free(minishell->currentDir);
	free(minishell->capturedLine);
	i = 0;
	free_char_arr(minishell->argv);
	free_char_arr(minishell->env_arr);
	minishell->argc = 0;
}

// static void	get_argc_argv(t_minishell *minishell ,char *str)
// {
// 	int	i;

// 	minishell->argv = ft_split(str, ' ');
// 	i = 0;
// 	while (minishell->argv[i])
// 		i++;
// 	minishell->argc = i;
// }

int	prompt(t_minishell *minishell)
{
	while (1)
	{
		ms_signals(minishell);
		minishell->currentDir = get_dir();
		if (!minishell->currentDir)
			return (1);
		minishell->capturedLine = readline(minishell->currentDir);
		if (!minishell->capturedLine)
		{
			free(minishell->currentDir);
			return (1);
		}
		if (argv_parser(minishell))
		{
			free_vars(minishell);
			continue ;
		}
		//get_argc_argv(minishell, minishell->capturedLine);
		for (int i = 0; i < minishell->argc; i++)
			ft_printf("%s\n", minishell->argv[i]);
		builtins_check(minishell);
		add_history(minishell->capturedLine);
		free_vars(minishell);
	}
	return (0);
}
