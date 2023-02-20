/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:53:02 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 15:04:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	define_var(char *var)
{
	int		i;
	int		len;
	char	**aux;

	len = 0;
	while (g_var.envp[len])
		len++;
	aux = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < len)
	{
		aux[i] = ft_strdup(g_var.envp[i]);
		i++;
	}
	aux[i] = ft_strdup(var);
	ft_free_matrix(g_var.envp);
	g_var.envp = ft_calloc(len + 2, sizeof(char *));
	i = 0;
	while (i < (len + 1))
	{
		g_var.envp[i] = ft_strdup(aux[i]);
		i++;
	}
	ft_free_matrix(aux);
	g_var.exit_code = 0;
}

static void	update_var(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_chrpos(var, '=');
	while (g_var.envp[i])
	{
		if (ft_memcmp(var, g_var.envp[i], len) == 0 && g_var.envp[i][len] == '=')
		{
			free(g_var.envp[i]);
			g_var.envp[i] = ft_strdup(var);
			break ;
		}
		i++;
	}
	g_var.exit_code = 0;
}

static int	already_env_var(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_chrpos(var, '=');
	while (g_var.envp[i])
	{
		if (ft_memcmp(var, g_var.envp[i], len) == 0 && g_var.envp[i][len] == '=')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	export_prompt(char **args)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (args[i])
	{
		temp = ft_strtrim(args[i], " \t");
		j = is_valid_attribution(temp, args[i + 1]);
		if (j == 1 || j == -1)
		{
			if (already_env_var(temp))
				update_var(temp);
			else
				define_var(temp);
			if (j == -1)
				i++;
		}
		free(temp);
		i++;
	}
}
