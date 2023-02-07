/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:08:19 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 16:25:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ms_cd(char *path)
{
	if (chdir(path) < 0)
		ft_printf("cd: %s : %s\n", strerror(errno), path);
}
