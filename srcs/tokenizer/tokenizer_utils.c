/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:46:15 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/22 17:10:36 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unclosed_quotes_error_msg(void)
{
	g_var.error = TRUE;
	g_var.exit_code = 22;
	g_var.invalid_input = TRUE;
	ft_putendl_fd("Unclosed quotes", STDERR_FILENO);
}

int	quotes_before_space(char *str)
{
	int	aux_double;
	int	aux_single;
	int	aux_space;

	if (str[0] == DOUBLE_QUOTES || str[0] == SINGLE_QUOTES)
		return (TRUE);
	else
	{
		aux_space = ft_chrpos(str, SPACE_VALUE);
		aux_double = ft_chrpos(str, DOUBLE_QUOTES);
		aux_single = ft_chrpos(str, SINGLE_QUOTES);
		if (aux_double == -1 && aux_single == -1)
			return (FALSE);
		if (aux_double != -1 && aux_space < aux_double)
			if (aux_single == -1 || aux_space < aux_single)
				return (FALSE);
		if (aux_single != -1 && aux_space < aux_single)
			if (aux_double == -1 || aux_space < aux_double)
				return (FALSE);
	}
	return (TRUE);
}

int	skip_spaces(int i, int j, char *input)
{
	if ((i + j) < ft_strlen(input) && input[i + j] == SPACE_VALUE)
	{
		j++;
		while ((i + j) < ft_strlen(input) && input[i + j]
			&& input[i + j] == SPACE_VALUE)
			j++;
	}
	return (j);
}

static void	update_save(char **save, t_list *char_list)
{
	char	*temp;

	temp = ft_strjoin(*save, char_list->content);
	free(*save);
	*save = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_memcpy(*save, temp, ft_strlen(temp));
	free(temp);
}

char	*join_list(t_list *char_list)
{
	char	*save;
	int		i;
	t_list	*tmp;

	if (char_list)
	{
		save = ft_calloc(ft_strlen(char_list->content) + 1, sizeof(char));
		i = 0;
		tmp = char_list;
		while (tmp)
		{
			if (i == 0)
				ft_memcpy(save, tmp->content,
					ft_strlen(tmp->content));
			else
				update_save(&save, tmp);
			tmp = tmp->next;
			i++;
		}
		return (save);
	}
	return (NULL);
}
