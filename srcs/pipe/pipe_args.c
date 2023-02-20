/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:05:39 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/20 10:58:29 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_last_pipe_arg(t_list **lst, char *str, int i, int j)
{
	char	*temp;
	char	*aux;

	if (str[j])
	{
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(temp);
		free(aux);
	}
	else
	{
		signal(SIGINT, pipe_stop);
		continue_add_pipe_arg(lst);
	}
}

int	increment_all_str_quotes(char *str, int i)
{
	if (str[i] && str[i] == DOUBLE_QUOTES)
	{
		if (ft_chrpos(str + i + 1, DOUBLE_QUOTES) != -1)
			i += ft_chrpos(str + i + 1, DOUBLE_QUOTES) + 1;
		else
			g_var.invalid_input = TRUE;
	}
	if (str[i] && str[i] == SINGLE_QUOTES)
	{
		if (ft_chrpos(str + i + 1, SINGLE_QUOTES) != -1)
			i += ft_chrpos(str + i + 1, SINGLE_QUOTES) + 1;
		else
			g_var.invalid_input = TRUE;
	}
	return (i);
}

static void	iterate_pipe_args(char *str, t_list **lst)
{
	int		i;
	int		j;
	char	*temp;
	char	*aux;

	i = 0;
	j = 0;
	// printf("HEY15\n");
	while (i < ft_strlen(str) && str[i] && !g_var.invalid_input)
	{
		i = increment_all_str_quotes(str, i);
		// printf("HEY16\n");
		if (str[i] == '|')
		{
			temp = ft_substr(str, j, i - j);
			aux = ft_strtrim(temp, " \t");
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
			free(temp);
			free(aux);
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			j = i + 1;
		}
		i++;
	}
	add_last_pipe_arg(lst, str, i, j);
}

char	**pipe_args(void)
{
	char	**args;
	t_list	*lst;

	lst = NULL;
	// printf("HEY12\n");
	iterate_pipe_args(g_var.input, &lst);
	// printf("HEY13\n");
	if (lst == NULL || g_var.invalid_input)
	{
		args = ft_calloc(2, sizeof(char *));
		args[0] = ft_strdup(g_var.input);
	}
	else
		args = ft_lst_to_matrix(lst);
	if (lst)
		ft_lstclear(&lst, free);
	// printf("HEY14\n");
	// printf("%s\n", args[0]);
	return (args);
}
