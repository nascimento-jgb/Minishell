/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:15:15 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:45:17 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	populate_redirect_lst(t_list **lst, char *str, int i, int j)
{
	char	*temp;
	char	*aux;

	if (str[i] == '>' || str[i] == '<')
	{
		if (i > 0 || j > 0)
		{
			temp = ft_substr(str, j, i - j);
			aux = ft_strtrim(temp, " \t");
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
			free(temp);
			free(aux);
			j = i;
		}
		while (str[i] == '>' || str[i] == '<')
			i++;
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		j = i;
		free(temp);
		free(aux);
	}
	return (i);
}

static void	split_redirect_args(char *str, t_list **lst)
{
	int		i;
	int		j;
	char	*temp;
	char	*aux;

	i = 0;
	j = 0;
	while (i < ft_strlen(str) && str[i] && !g_var.invalid_input)
	{
		i = increment_all_str_quotes(str, i);
		if (str[i] == '>' || str[i] == '<')
		{
			i = populate_redirect_lst(lst, str, i, j);
			j = i;
		}
		i++;
	}
	if (str[j])
	{
		temp = ft_substr(str, j, i - j);
		aux = ft_strtrim(temp, " \t");
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(temp);
		free(aux);
	}
}

char	**redirect_args(char **temp)
{
	int		i;
	char	**args;
	t_list	*redirect_args_list;

	i = 0;
	redirect_args_list = NULL;
	while (temp[i])
		split_redirect_args(temp[i++], &redirect_args_list);
	args = ft_lst_to_matrix(redirect_args_list);
	ft_lstclear(&redirect_args_list, free);
	ft_free_matrix(temp);
	return (args);
}
