/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:18:19 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:19:39 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	env_prompt(void)
{
	int	i;

	i = 0;
	while (g_var.envp[i])
		printf("%s\n", g_var.envp[i++]);
	g_var.exit_code = 0;
}
