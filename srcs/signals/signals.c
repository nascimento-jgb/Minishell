/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:03:07 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

void	handle_sigcount(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ms_signals(t_minishell *minishell)
{
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = &handle_sigcount;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	(void)minishell;
}
