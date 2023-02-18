/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_delnode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:48:43 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:50 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

void	vars_delnode(t_vars *node)
{
	if (!node)
		return ;
	ft_strdel(&node->key);
	ft_strdel(&node->path);
	ft_strdel(&node->value);
	free(node);
}
