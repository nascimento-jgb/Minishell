/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/07 15:35:45 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	signalDetect = 1;

void	handle_sigcount(int sig)
{
	if (sig == SIGINT)
	{
		//char *str;

		//str = ft_strdup("Error hapened\n");
		//write(2, str, ft_strlen(str));
		ft_putstr_fd("\n", 2);
		//rl_replace_line("", 0);
		rl_on_new_line();
		signalDetect = 0;
	}

}

void	ms_signals(t_minishell *minishell)
{
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = (void (*)(int))handle_sigcount;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	if (!signalDetect)
	{
		minishell->signalDetect = 1;
		//prompt(minishell);
	}
	//signal(SIGINT, (void (*)(int))handle_sigcount);
}
