/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/13 11:05:53 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_spaces(char *message)
{
	while (*message)
	{
		if (!ft_isspace(*message))
			ft_putchar(*message);
		else if (ft_isspace(*message) && !ft_isspace(*(message + 1)))
			ft_putchar(*message);
		message++;
	}
}

void	ms_echo(char *message, int flag)
{
	remove_spaces(message);
	if (!flag)
		ft_putchar('\n');
}
