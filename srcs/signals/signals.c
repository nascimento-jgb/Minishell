/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/08 09:33:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	signalDetect = 1;

void	handle_sigcount(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		//rl_replace_line("", 0);
		//rl_on_new_line();
		//rl_redisplay();
		signalDetect = 0;
	}

}

void	ms_signals(t_minishell *minishell)
{
	// struct sigaction sa;
	// sa.__sigaction_u.__sa_handler = &handle_sigcount;
	// sa.sa_flags = SA_RESTART;
	// if (sigaction(SIGINT, &sa, NULL) == (int)SIG_ERR)
	// 	ft_putendl_fd("Failed to handle the interrupt signal", 2);
	// if (!signalDetect)
	// 	minishell->signalDetect = 0;
	if (!signal(SIGINT, &handle_sigcount))
		minishell->signalDetect = 0;
}
