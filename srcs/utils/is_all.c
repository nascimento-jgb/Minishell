/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:54:21 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 15:32:43 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_all_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
				|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	is_all_digit(char *c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (!(c[i] >= '0' && c[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_all_dollar(char *str)
{
	int	i;

	if (!str)
		return (FALSE);
	i = 0;
	while (str[i])
		if (!(str[i++] == DOLLAR_SIGN))
			return (FALSE);
	return (TRUE);
}

int	is_all_valid_history(char *str)
{
	if (str && *str)
	{
		if (str[0] == '\t' || str[0] == '\v' || str[0] == '\r' || str[0] == ' ')
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
}
