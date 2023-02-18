/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_removenode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:53:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:44 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

static void	remove_middle(t_vars **list, t_vars *node)
{
	t_vars	*tmp;
	t_vars	*delnode;

	tmp = *list;
	while (tmp)
	{
		if (tmp->next->key == node->key)
		{
			delnode = tmp->next;
			tmp->next = tmp->next->next;
			vars_delnode(delnode);
			return ;
		}
		tmp = tmp->next;
	}
}

void	vars_remove_node(t_vars **list, t_vars *node)
{
	t_vars	*tmp;

	if (!list || !*list || !node)
		return ;
	if ((*list)->key == node->key)
	{
		tmp = (*list)->next;
		vars_delnode(*list);
		*list = tmp;
	}
	else
		remove_middle(list, node);
}
