/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/08 18:08:37 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigcount(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}

}

void	ms_signals(void)
{
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = &handle_sigcount;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == (int)SIG_ERR)
		ft_putendl_fd("Failed to handle the interrupt signal", 2);
	// if (!signalDetect)
	// 	minishell->signalDetect = 0;
	// if (!signal(SIGINT, &handle_sigcount))
	// 	minishell->signalDetect = 0;
}
