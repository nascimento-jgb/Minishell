/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:49:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 13:00:54 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_list	*find_var(t_list *list ,char *var)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, var, ft_strlen(var)))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

static void delete(void *mem)
{
	free(mem);
	mem = NULL;
}

int	unset(t_minishell *minishell, char *var)
{
	t_list *node;

	node = find_var(minishell->vars->vars_list, var);
	if (node)
	{
		ft_lstdelone(node, delete);
		return(0);
	}
	return(1);
}