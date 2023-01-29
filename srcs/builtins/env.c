/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:10:02 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 13:10:52 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_env(t_vars *env)
{
	t_vars *tmp;

	tmp = env;
	while (tmp)
	{
		ft_printf("%s\n", tmp->path);
		tmp = tmp->next;
	}
}
