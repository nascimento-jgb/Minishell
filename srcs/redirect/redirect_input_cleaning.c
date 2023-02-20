/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_input_cleaning.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:50:35 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:45:17 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	update_input(char **input, char *arg, int j)
{
	char	*temp;
	char	*aux;

	if (j == 0)
		temp = ft_strdup(arg);
	else
	{
		aux = ft_strjoin(" ", arg);
		temp = ft_strjoin(*input, aux);
		free(aux);
	}
	free(*input);
	*input = ft_strdup(temp);
	free(temp);
	j++;
	return (j);
}

void	redirect_input_cleaning(char **args, char **input)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if ((ft_chrqty(args[i], '>') == 0 && ft_chrqty(args[i], '<') == 0)
			|| (args[i][0] != '>' && args[i][0] != '<'))
			j = update_input(input, args[i], j);
		else
			i++;
		i++;
	}
	if (j == 0 && args[j] && (ft_chrqty(args[0], '>') != 0
			|| ft_chrqty(args[0], '<') != 0))
	{
		free(*input);
		*input = ft_strjoin("", "");
	}
}
