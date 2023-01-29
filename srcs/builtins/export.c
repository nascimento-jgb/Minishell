/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:23:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 15:02:05 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	path_length(char *path)
{
	int i;

	i = 0;
	while (path[i] && path[i] != '=')
		i++;
	return (i);
}

static int validate_path(char *path)
{
	int	i;
	int	equal;

	equal = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == '=')
			equal++;
		if (ft_isspace(path[i]))
			return (1);
		i++;
	}
	if (equal != 1)
		return (1);
	return (0);
}

static int	check_duplicate(t_vars *env, char *path)
{
	t_vars *tmp;
	
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->path, path, path_length(path)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ms_export(t_minishell *minishell, char *path)
{
	t_vars	*node;
	
	if (validate_path(path))
		return(1);
	if (check_duplicate(minishell->env->vars_list, path))
		return (1);
	node = vars_new(path);
	if (!node)
		return (1);
	vars_addback(&minishell->env->vars_list, node);
	return (0);
}
