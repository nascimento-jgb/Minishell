/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:44:24 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 14:40:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_listclear(t_vars **list)
{
	t_vars *tmp;
	
	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			vars_delnode(*list);
			*list = tmp;
		}
	}
}