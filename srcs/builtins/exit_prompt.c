/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:05:43 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 17:24:15 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_prompt(void)
{
	if (g_var.input)
		free(g_var.input);
	if (g_var.envp)
		free(g_var.envp);
	if (g_var.prompt_line)
		free(g_var.prompt_line);
	rl_clear_history();
	exit(0);
}

void	check_eof(char *input)
{
	if (input)
		return ;
	printf("exit\n");
	exit_prompt();
}
