/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:26:02 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 14:46:05 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	delete(void *mem)
{
	free(mem);
	mem = NULL;
	//(void)mem;
}

void	clean_minishell(t_minishell *minishell)
{
	if (minishell)
	{
		if (minishell->env)
		{
			if (minishell->env->vars_list)
				vars_listclear(&minishell->env->vars_list);
			free(minishell->env);
		}
		free(minishell);
	}
}