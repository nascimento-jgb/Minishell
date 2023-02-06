/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:36:20 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/06 18:05:24 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigcount(int sig)
{
	(void)sig;
	char *str;

	str = ft_strdup("Error hapened\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
}

void	ms_signals(void)
{
	struct sigaction sa;
	sa.__sigaction_u.__sa_handler = (void (*)(int))handle_sigcount;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	//signal(SIGINT, (void (*)(int))handle_sigcount);
}
