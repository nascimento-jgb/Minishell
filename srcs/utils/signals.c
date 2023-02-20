/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:48:04 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/20 09:16:12 by jonascim         ###   ########.fr       */
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
		rl_done = TRUE;
		close(rl_instream->_file);
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
		rl_done = TRUE;
		close(rl_instream->_file);
	}
	return ;
}

void	new_line(int signal)
{
	(void)signal;
	g_var.exit_code = 130;
	g_var.invalid_input = TRUE;
	g_var.error = TRUE;
	ft_putendl_fd("", g_var.initial_fd[OUT]);
}

void	quit_exec(int signal)
{
	(void)signal;
	g_var.exit_code = 131;
	g_var.error = TRUE;
	g_var.invalid_input = TRUE;
	ft_putendl_fd("Quit ", STDERR_FILENO);
}

void	new_prompt(int signal)
{
	(void)signal;
	g_var.exit_code = 130;
	ft_putendl_fd("", g_var.initial_fd[OUT]);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
