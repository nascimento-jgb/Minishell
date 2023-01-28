/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:23:04 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 12:48:28 by andrferr         ###   ########.fr       */
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

	i = 0;
	while (path[i])
	{
		if (ft_isspace(path[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(t_list *env, char *path)
{
	t_list *tmp;
	
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, path, path_length(path)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ms_export(t_minishell *minishell, char *path)
{
	if (validate_path(path))
		return(1);
	if (check_duplicate(minishell->env->env_list, path))
		return (1);
	ft_lstadd_back(&minishell->env->env_list, ft_lstnew(path));
	return (0);
}
