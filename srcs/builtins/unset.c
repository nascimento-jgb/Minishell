/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:49:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/30 11:28:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_vars	*find_var(t_vars *list, char *var)
{
	t_vars	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->path, var, ft_strlen(var)))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

int	ms_unset(t_minishell *minishell, char *var)
{
	t_vars	*node;

	node = find_var(minishell->env->vars_list, var);
	if (node)
		vars_remove_node(&minishell->env->vars_list, node);
	return (1);
}
