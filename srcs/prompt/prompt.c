/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/13 17:25:59 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	free_vars(t_minishell *minishell)
{
	int	i;

	free(minishell->currentDir);
	free(minishell->capturedLine);
	i = 0;
	free_char_arr(minishell->argv);
	free_char_arr(minishell->env_arr);
	minishell->argc = 0;
}

static void	get_argc_argv(t_minishell *minishell, char *str)
{
	int	i;

	minishell->argv = ft_split(str, ' ');
	i = 0;
	while (minishell->argv[i])
		i++;
	minishell->argc = i;
}

int	fork_create(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit_message("Fork error.\n");
	else
		return (pid);
	return (0);
}

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
		get_argc_argv(minishell, minishell->capturedLine);
		builtins_check(minishell);
		add_history(minishell->capturedLine);
		free_vars(minishell);
	}
	return (0);
}

// int	prompt(t_minishell *minishell)
// {
// 	while ((minishell->capturedLine = readline((minishell->currentDir = get_dir()))) >= 0)
// 	{
// 		ms_signals(minishell);
// 		get_argc_argv(minishell, minishell->capturedLine);
// 		if (minishell->capturedLine[0] == 'c' && minishell->capturedLine[1] == 'd' && minishell->capturedLine[2] == ' ')
// 		{
// 			minishell->capturedLine[ft_strlen(minishell->capturedLine)-1] = 0;
// 			if (chdir(minishell->capturedLine+3) < 0)
// 				ft_printf("cannot cd %s", minishell->capturedLine+3);
// 			continue ;
// 		}
// 		if (fork_create() == 0)
// 			run_command(parse_command(minishell->capturedLine), minishell);
// 		wait(NULL);
// 		add_history(minishell->capturedLine);
// 		free_vars(minishell);
// 	}
// 	return (0);
// }
