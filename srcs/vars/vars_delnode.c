/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_delnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:48:43 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/30 11:10:15 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	vars_delnode(t_vars *node)
{
	if (!node)
		return ;
	ft_strdel(&node->key);
	ft_strdel(&node->path);
	ft_strdel(&node->value);
	free(node);
}
