/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:48 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/13 11:10:59 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_check(t_minishell *minishell)
{
	if (minishell->capturedLine[0] == 'c' && minishell->capturedLine[1] == 'd' && minishell->capturedLine[2] == ' ')
	{
		minishell->capturedLine[ft_strlen(minishell->capturedLine) - 1] = 0;
		ms_cd(minishell->capturedLine + 3);
	}
	else if (minishell->capturedLine[0] == 'e' && minishell->capturedLine[1] == 'c' && minishell->capturedLine[2] == 'h'
	&& minishell->capturedLine[3] == 'o' && minishell->capturedLine[4] == ' ')
	{
		minishell->capturedLine[ft_strlen(minishell->capturedLine) - 1] = 0;
		if (minishell->capturedLine[5] == '-' && minishell->capturedLine[6] == 'n')
			ms_echo(minishell->capturedLine + 7, 0);
		else
			ms_echo(minishell->capturedLine + 5, 1);
	}
	else if (minishell->capturedLine[0] == 'e' && minishell->capturedLine[1] == 'x' && minishell->capturedLine[2] == 'i'
	&& minishell->capturedLine[3] == 't')
	{
		minishell->capturedLine[ft_strlen(minishell->capturedLine) - 1] = 0;
		ms_exit(0);
	}
	else if (minishell->capturedLine[0] == 'e' && minishell->capturedLine[1] == 'n' && minishell->capturedLine[2] == 'v'
	&& minishell->capturedLine[3] == ' ')
	{
		minishell->capturedLine[ft_strlen(minishell->capturedLine) - 1] = 0;
		ms_env(minishell->env->vars_list);
	}
	if (fork_create() == 0)
		run_command(parse_command(minishell->capturedLine), minishell);
	wait(NULL);
}
