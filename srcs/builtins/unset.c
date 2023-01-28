/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:49:18 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 21:46:00 by andrferr         ###   ########.fr       */
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

static void delete(void *content)
{
	free(content);
	content = NULL;
}

int	ms_unset(t_minishell *minishell, char *var)
{
	t_list	*tmp;
	t_list	*node;

	node = find_var(minishell->env->env_list, var);
	if (node)
	{
		tmp = minishell->env->env_list;
		if (tmp == node)
		{
			ft_lstclear(&minishell->env->env_list, delete);
			return (0);
		}
		while (tmp)
		{
			if (tmp->next == node)
			{
				tmp->next = tmp->next->next;
				ft_lstdelone(node, delete);
				return(0);
			}
			tmp = tmp->next;
		}
	}
	return(1);
}