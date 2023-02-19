/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:48:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:33:23 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_stop(int signal)
{
	if (signal == SIGINT)
	{
		g_var.exit_code = 130;
		g_var.error = TRUE;
		g_var.invalid_input = TRUE;
		ft_putendl_fd("", g_var.initial_fd[OUT]);
		rl_replace_line("", 0);
		//rl_done = TRUE;
		//close(rl_instream->_fileno);
	}
	return ;
}

void	here_doc_stop(int signal)
{
	if (signal == SIGINT)
	{
		g_var.exit_code = 130;
		g_var.error = TRUE;
		g_var.invalid_input = TRUE;
		ft_putendl_fd("", OUT);
		rl_replace_line("", 0);
		// rl_done = TRUE;
		// close(rl_instream->_fileno);
	}
	return ;
}

void	new_line(int signal)
{
	(void)signal;
	g_var.exit_code = 130;
	g_var.invalid_input = TRUE;
	g_var.error = TRUE;
	ft_putendln_fd("", g_var.initial_fd[OUT]);
}

void	quit_exec(int signal)
{
	(void)signal;
	g_var.exit_code = 131;
	g_var.error = TRUE;
	g_var.invalid_input = TRUE;
	ft_putendln_fd("Quit ", STDERR_FILENO);
}

void	new_prompt(int signal)
{
	(void)signal;
	g_var.exit_code = 130;
	ft_putendln_fd("", g_var.initial_fd[OUT]);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
