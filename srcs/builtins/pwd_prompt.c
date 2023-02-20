/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:15:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/20 16:53:39 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_prompt(void)
{
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	printf("%s\n", pwd);
	free(pwd);
	g_var.exit_code = 0;
}
