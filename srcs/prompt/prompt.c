/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 11:55:25 by andrferr         ###   ########.fr       */
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
	char	*a;

	while (1)
	{
		minishell->promptLine = get_dir();
		if (!minishell->promptLine)
			return (1);
		a = readline(minishell->promptLine);
		if (!a)
		{
			free(minishell->promptLine);
			return (1);
		}
		parse_command(a);
		add_history(a);
		ms_pwd();
		free_vars(minishell->promptLine, a);
	}
	return (0);
}
