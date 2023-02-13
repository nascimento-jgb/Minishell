/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:26:02 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/13 13:14:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (minishell->last_cmd)
			ft_strdel(&minishell->last_cmd);
		if (minishell->cmd)
			ft_strdel(&minishell->cmd);
		free(minishell);
	}
}

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
}
