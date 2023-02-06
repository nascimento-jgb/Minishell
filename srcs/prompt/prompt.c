/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:38:39 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/06 16:04:29 by andrferr         ###   ########.fr       */
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
	char	*dir;

	while (1)
	{
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
		free_vars(dir, a);
	}
	return (0);
}
