/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:18:10 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/22 10:02:49 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	add_var(char *var, int len, t_list **char_list)
{
	int	i;

	i = 0;
	while (g_var.envp[i])
	{
		if (ft_memcmp(var, g_var.envp[i], len) == 0
			&& g_var.envp[i][len] == '=')
		{
			if (g_var.envp[i][len + 1])
				ft_lstadd_back(char_list, ft_lstnew(ft_substr(g_var.envp[i],
							len + 1, ft_strlen(g_var.envp[i]) - len - 1)));
			else
				ft_lstadd_back(char_list, ft_lstnew(ft_strjoin("", "")));
			break ;
		}
		i++;
	}
	return (i);
}

static void	save_var(char *str, t_list **char_list)
{
	int		i;
	int		len;
	char	*var;

	if (str[0] == '?')
	{
		ft_lstadd_back(char_list, ft_lstnew(ft_itoa(g_var.exit_code)));
		return ;
	}
	i = 0;
	while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i])))
		i++;
	var = ft_substr(str, 0, i);
	len = ft_strlen(var);
	i = add_var(var, len, char_list);
	if (g_var.envp[i] == NULL)
		ft_lstadd_back(char_list, ft_lstnew(ft_strjoin("", "")));
	free(var);
}

static int	iterate_and_replace(char *str, t_list **char_list)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str) && str[i])
	{
		i = ft_chrpos(str, DOLLAR_SIGN);
		if (i == -1)
		{
			ft_lstadd_back(char_list, ft_lstnew(ft_strdup(str)));
			return (ft_strlen(str));
		}
		else if (i == 0)
		{
			save_var(str + 1, char_list);
			i++;
			while (str[i] && (ft_isalpha(str[i]) || ft_isdigit(str[i])))
				i++;
			if (str[1] == '?')
				i++;
		}
		else
			ft_lstadd_back(char_list, ft_lstnew(ft_substr(str, 0, i)));
		i += iterate_and_replace(str + i, char_list);
	}
	return (i);
}

char	**replace_env_var(char **temp)
{
	int		i;
	char	**args;
	t_list	*char_list;

	args = ft_calloc(g_var.args_num + 1, sizeof(char *));
	i = 0;
	while (i < g_var.args_num)
	{
		char_list = NULL; // check if there is presence of single quotes at the beggining/end without dollasign in the middle
		if (((temp[i][0] == SINGLE_QUOTES || (temp[i][0] == SPACE_VALUE
				&& temp[i][1] == SINGLE_QUOTES)) && temp[i][ft_strlen(temp[i])
				- 1] == SINGLE_QUOTES) || ft_chrpos(temp[i], DOLLAR_SIGN) == -1)
			ft_lstadd_back(&char_list, ft_lstnew(ft_strdup(temp[i])));
		else
			iterate_and_replace(temp[i], &char_list);
		args[i] = join_list(char_list);
		ft_lstclear(&char_list, free);
		i++;
	}
	args[i] = NULL;
	ft_free_matrix(temp);
	return (args);
}
