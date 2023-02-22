/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:04:05 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/22 17:04:27 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**copy_and_clear_env(char *var, int i)
{
	char	**aux;
	int		j;
	int		len;

	aux = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	j = 0;
	len = ft_strlen(var);
	while (g_var.envp[i])
	{
		if (ft_memcmp(var, g_var.envp[i], len)
			== 0 && g_var.envp[i][len] == '=')
			j--;
		else
			aux[j] = ft_strdup(g_var.envp[i]);
		i++;
		j++;
	}
	aux[j] = NULL;
	return (aux);
}

static void	clear_var(char *var)
{
	int		i;
	char	**aux;

	i = 0;
	while (g_var.envp[i])
		i++;
	aux = copy_and_clear_env(var, i);
	ft_free_matrix(g_var.envp);
	g_var.envp = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (aux[i])
	{
		g_var.envp[i] = ft_strdup(aux[i]);
		i++;
	}
	ft_free_matrix(aux);
	g_var.exit_code = 0;
}

static int	is_valid_unset(char *var)
{
	int	i;
	int	error;

	i = 0;
	error = TRUE;
	if (ft_chrpos(var, '=') != -1)
		error = FALSE;
	while (var[i] && error)
	{
		if (!(ft_isalpha(var[i]) || ft_isdigit(var[i]))
			|| is_all_digit(var, ft_strlen(var)))
			error = FALSE;
		i++;
	}
	if (!error)
	{
		ft_putstr_fd("unset '", STDERR_FILENO);
		ft_putstr_fd(var, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		g_var.exit_code = 1;
	}
	return (error);
}

void	unset_prompt(char **args)
{
	int		i;
	char	*temp;

	i = 1;
	while (args[i])
	{
		temp = ft_strtrim(args[i], " \t");
		if (is_valid_unset(temp))
			clear_var(temp);
		i++;
		free(temp);
	}
}
