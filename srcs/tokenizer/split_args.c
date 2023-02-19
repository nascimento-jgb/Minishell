/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:46:25 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/18 15:58:58 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*save_arg(char *str, int len)
{
	char	*arg;

	arg = ft_calloc(len + 1, sizeof(char *));
	ft_memcpy(arg, str, len);
	return (arg);
}

void	split_args(char **args, char *input)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < ft_strlen(input) && input[i])
	{
		j = increment_quotes(i, input);
		if ((i + j) < ft_strlen(input) && input[i + j] != DOUBLE_QUOTES && input[i + j] != SINGLE_QUOTES && input[i + j] != SPACE_VALUE)
			j = increment_count(i + j, SPACE_VALUE, input) - i;
		if (index <= 1)
			args[index] = save_arg(input + i, j);
		else
			args[index] = save_arg(input + i - 1, j + 1);
		index++;
		j = skip_spaces(i, j, input);
		i += j;
	}
}
