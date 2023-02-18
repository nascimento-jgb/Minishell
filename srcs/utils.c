/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:45:21 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:08 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

char **env_to_arr(t_minishell *minishell)
{
	char **arr;
	t_vars *tmp;
	int	i;

	arr = ft_calloc(vars_length(minishell) + 1, sizeof(char *));
	if (!arr)
		return (0);
	tmp = minishell->env->vars_list;
	i = 0;
	while (tmp)
	{
		arr[i] = ft_strdup(tmp->path);
		if (!arr[i])
		{
			free(arr);
			return (NULL);
		}
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}
