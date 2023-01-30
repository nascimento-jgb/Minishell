/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_removenode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:53:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/30 09:48:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_remove_node(t_vars **list, t_vars *node)
{
	t_vars	*tmp;
	t_vars	*delndode;
	
	if (!list || !*list || !node)
		return ;
	if ((*list)->key == node->key)
	{
		tmp = (*list)->next;
		vars_delnode(*list);
		*list = tmp;
	}
	else
	{
		tmp = *list;
		while (tmp)
		{
			if (tmp->next->key == node->key)
			{
				delndode = tmp->next;
				tmp->next = tmp->next->next;
				vars_delnode(delndode);
				return ;
			}
			tmp = tmp->next;
		}
	}
}