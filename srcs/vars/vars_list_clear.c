/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_list_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:44:24 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:47 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

void	vars_listclear(t_vars **list)
{
	t_vars	*tmp;

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
