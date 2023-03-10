/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:57:46 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/20 16:20:56 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	increment_count(int i, int c, char *input)
{
	i++;
	while (i < ft_strlen(input) && input[i] && input[i] != c)
		i++;
	return (i);
}

int	increment_quotes(int i, char *input)
{
	int	aux_double;
	int	aux_single;
	int	j;

	j = 0;
	while ((i + j) < ft_strlen(input) && quotes_before_space(input + i + j))
	{
		if (input[i + j] == DOUBLE_QUOTES)
			j += increment_count(i + j, DOUBLE_QUOTES, input) + 1 - i - j;
		else if (input[i + j] == SINGLE_QUOTES)
			j += increment_count(i + j, SINGLE_QUOTES, input) + 1 - i - j;
		else
		{
			aux_double = increment_count(i + j, DOUBLE_QUOTES, input);
			aux_single = increment_count(i + j, SINGLE_QUOTES, input);
			if (aux_single < aux_double)
				j += aux_single - i - j;
			else
				j += aux_double - i - j;
		}
	}
	return (j);
}

static void	count_args(char *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(input) && input[i])
	{
		j = increment_quotes(i, input);
		if ((i + j) < ft_strlen(input)
			&& input[i + j] != DOUBLE_QUOTES
			&& input[i + j] != SINGLE_QUOTES
			&& input[i + j] != SPACE_VALUE)
			j = increment_count(i + j, SPACE_VALUE, input) - i;
		g_var.args_num++;
		j = skip_spaces(i, j, input);
		i += j;
	}
}

char	**tokenizer(char *input)
{
	char	**args;

	g_var.args_num = 0;
	if (input)
		count_args(input);
	else
		count_args(g_var.input);
	args = ft_calloc(g_var.args_num + 1, sizeof(char *));
	if (input)
		split_args(args, input);
	else
		split_args(args, g_var.input);
	return (args);
}
