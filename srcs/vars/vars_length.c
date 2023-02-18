/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:47:37 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:54 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

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
