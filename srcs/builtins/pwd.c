/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:28:03 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 15:39:58 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(void)
{
	char dir[1024];

	if (!getcwd(dir, 1024))
	{
		blt_error_msg("pwd", errno, "pwd");
		return ;
	}
	ft_printf("%s\n", dir);
}
