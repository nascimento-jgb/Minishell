/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:47:37 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	vars_length(t_minishell *minishell)
{
	t_vars *tmp;
	int i;

	if (!minishell->env->vars_list)
		return (0);
	i = 0;
	tmp = minishell->env->vars_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
