/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:17:05 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 12:40:06 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


t_vars	*vars_init(void)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->vars_list = NULL;
	vars->total_vars = 0;
	return (vars);
}