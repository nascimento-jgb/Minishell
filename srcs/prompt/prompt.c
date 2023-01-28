/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 12:42:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	prompt(t_minishell *minishell)
{
	while (1)
	{
		char	*a;
		char	*dir;

		dir = get_dir();
		if (!dir)
			return (1);
		a = readline(dir);
		if (!a)
		{
			free(dir);
			return (1);
		}
		add_history(a);
		printf("%s\n", a);
		ms_env(minishell->env->env_list);
		ms_export(minishell, a);
		ms_env(minishell->env->env_list);
		free(dir);
		free(a);
	}
	//rl_clear_history();
	return (0);
}
