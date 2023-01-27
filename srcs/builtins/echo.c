/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 16:01:03 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_spaces(char *message)
{
	int	i;

	i = 0;
	while (*message)
	{
		if (!ft_isspace(*message))
			ft_putchar(*message);
		else if (ft_isspace(*message) && !ft_isspace(*(message + 1)))
			ft_putchar(*message);
		message++;
	}
}

void	echo(char *message, int	flag)
{
	remove_spaces(message);
	if (!flag)
		ft_putchar('\n');
}
