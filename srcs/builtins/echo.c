/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:40:26 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/15 10:29:57 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	remove_spaces(char *message, int nbr_quotes)
{
	int	len;
	int i;

	len = ft_strlen(message);
	if (nbr_quotes)
	{
		len--;
		message++;
	}
	i = 0;
	while (i < len - 1)
	{
		if (!ft_isspace(*message))
			ft_putchar(*message);
		else if (ft_isspace(*message) && !ft_isspace(*(message + 1)))
			ft_putchar(*message);
		message++;
		i++;
	}
}

static int check_double_quotes(char *path, int *nbr_quotes)
{
	int	i;

	i = -1;
	while (path[++i])
		if (path[i] == 34)
			(*nbr_quotes)++;
	if (*nbr_quotes == 0 || *nbr_quotes == 2)
		return (*nbr_quotes);
	else
		return (-1);
}

void	ms_echo(char *message, int flag)
{
	int	nbr_quotes;

	nbr_quotes = 0;
	check_double_quotes(message, &nbr_quotes);
	if (nbr_quotes != 0 && nbr_quotes != 2)
	{
		ft_putendl_fd("Wrong number of double quotes. Please try again. If you open double quotes, remember to close it.", 2);
		return ;
	}
	else
		remove_spaces(message, nbr_quotes);
	if (!flag)
		ft_putchar('\n');
}
