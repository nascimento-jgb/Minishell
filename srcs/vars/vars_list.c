/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 08:24:05 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:46 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes2/minishell2.h"

static int	validate_path(char *path)
{
	int	i;
	int	equal;

	equal = 0;
	i = 0;
	while (path[i])
	{
		if (path[i] == '=')
			equal++;
		if (ft_isspace(path[i]))
			return (1);
		i++;
	}
	if (equal != 1)
		return (1);
	return (0);
}

static char	*get_key(char *var)
{
	int		i;
	int		j;
	char	*key;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	key = (char *)malloc(sizeof(char) * i + 1);
	if (!key)
		return (NULL);
	j = -1;
	while (++j < i)
		key[j] = var[j];
	key[j] = '\0';
	return (key);
}

static char	*get_value(char *var)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	i++;
	value = (char *)malloc(sizeof(char) * (ft_strlen(var) - i) + 1);
	if (!value)
		return (NULL);
	j = 0;
	while (var[i])
		value[j++] = var[i++];
	value[j] = '\0';
	return (value);
}

t_vars	*new_var(char *var)
{
	t_vars	*new;

	if (validate_path(var))
		return (NULL);
	new = ft_calloc(1, sizeof(t_vars));
	if (!new)
		return (NULL);
	new->path = ft_strdup(var);
	new->key = get_key(var);
	new->value = get_value(var);
	new->next = NULL;
	return (new);
}
