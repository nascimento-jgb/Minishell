/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:16:50 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/13 17:19:14 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_minishell	*minishell_init(char **env)
{
	t_minishell	*minishell;

	minishell = ft_calloc(1, sizeof(t_minishell));
	if (!minishell)
		return (NULL);
	minishell->env = env_init(env);
	minishell->signalDetect = 1;
	return (minishell);
}
