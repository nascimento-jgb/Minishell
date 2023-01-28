/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:03:35 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 11:05:55 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	total_env_vars(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

static int	env_populate(char **env, t_env *env_t)
{
	t_list	*env_list;
	int		i;

	i = 0;
	env_list = NULL;
	while (i < total_env_vars(env))
	{
		ft_lstadd_back(&env_list, ft_lstnew(env[i]));
		i++;
	}
	env_t->total_env_vars = i;
	env_t->env_list = env_list;
	return (0);
}

t_env *env_init(char **env)
{
	t_env	*env_t;
	
	env_t = (t_env *)malloc(sizeof(t_env));
	if (!env_t)
		return (NULL);
	if (env_populate(env, env_t))
		return (NULL);
	return (env_t);
}