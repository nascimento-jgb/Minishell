/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:26:02 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 12:45:00 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	delete(void *mem)
{
	free(mem);
	mem = NULL;
}

void	clean_minishell(t_minishell *minishell)
{
	if (minishell)
	{
		if (minishell->env)
		{
			if (minishell->env->env_list)
				ft_lstclear(&minishell->env->env_list, delete);
			free(minishell->env);
		}
		if (minishell->vars)
		{
			if (minishell->vars->vars_list)
				ft_lstclear(&minishell->vars->vars_list, delete);
			free(minishell->vars);
		}
		free(minishell);
	}
}