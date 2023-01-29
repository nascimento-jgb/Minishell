/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:03:35 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 17:13:42 by andrferr         ###   ########.fr       */
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
	t_vars	*env_list;
	t_vars	*node;
	int		i;

	i = 0;
	env_list = NULL;
	while (i < total_env_vars(env))
	{
		node = vars_new(env[i]);
		vars_addback(&env_list, node);
		i++;
	}
	env_t->total_env_vars = i;
	env_t->vars_list = env_list;
	return (0);
}

t_env *env_init(char **env)
{
	t_env	*env_t;
	
	env_t = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!env_t)
		return (NULL);
	if (env_populate(env, env_t))
		return (NULL);
	return (env_t);
}