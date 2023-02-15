/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:27:48 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/15 10:33:34 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_check(t_minishell *minishell)
{
	if (!ft_strncmp(minishell->capturedLine, "cd ", 3))
		ms_cd(minishell->capturedLine + 3);
	else if (!ft_strncmp(minishell->capturedLine, "echo ", 5))
	{
		if (minishell->capturedLine[5] == '-' && minishell->capturedLine[6] == 'n')
			ms_echo(minishell->capturedLine + 7, 1);
		else
			ms_echo(minishell->capturedLine + 5, 0);
	}
	else if (!ft_strncmp(minishell->capturedLine, "exit ", 5))
		ms_exit(0);
	else if (!ft_strncmp(minishell->capturedLine, "env ", 4))
		ms_env(minishell->env->vars_list);
	else
	{
		if (fork_create() == 0)
			run_command(parse_command(minishell->capturedLine), minishell);
		wait(NULL);
	}
}
