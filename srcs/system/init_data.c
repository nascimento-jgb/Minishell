/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:49:27 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:32:12 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*prompt_line_str(void)
{
	char	*str;
	char	*pwd;
	char	*aux;
	char	*temp;

	pwd = getcwd(NULL, 0);
	temp = ft_strjoin("\e[1;36mAndre&Joao-SHELL\e[0m>\e[1;34m", pwd);
	aux = ft_strjoin(temp, "\e[0m");
	str = ft_strjoin(aux, "\e[1;32m$\e[0m ");
	free(pwd);
	free(temp);
	free(aux);
	return (str);
}

void	init_gvar_data(void)
{
	g_var.args_num = 0;
	g_var.error = FALSE;
	g_var.close_code = FALSE;
	g_var.invalid_input = FALSE;
	g_var.prompt_line = prompt_line_str();
	g_var.input = NULL;
}

char	**dup_env(char **envp)
{
	int		len;
	int		i;
	char	**aux;

	len = 0;
	i = 0;
	while (envp[len])
		len++;
	aux = ft_calloc(len + 1, sizeof(char *));
	while (i < len)
		aux[i] = ft_strdup(envp[i++]);
	aux[i] = NULL;
	return (aux);
}

void	initial_message(void)
{
	printf("\n\n----------------------------------------------\n\n");
	printf("\t\tThis is minishell\t\t\n");
	printf("\tUse it at your own risk\t\n");
	printf("\n\n----------------------------------------------\n\n");
}
