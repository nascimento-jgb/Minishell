/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/18 15:44:36 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_general(char	**input)
{
	int		code;
	char	**args;

	redirect(input);
	args = clean_quotes(repalce_env_var(tokenizer(*input)));
	if (!g_var.error && args[0])
	{
		code = is_builtin(args);
		if (code)
			exec_builtin(args, code);
		else
			exec_cmd(redirect_args(args));
	}
	ft_free_matrix(args);
}

static void	exec_args(void)
{
	if (!is_exit_cmd())
	{
		save_fd(g_var.initial_fd);
		g_var.old_pipe_in = 0;
		pipe_checker();
		change_fd(g_var.initial_fd);
	}
	else
		exit_prompt();
}

static int	is_valid_input(char *input)
{
	char	*aux;
	char	**temp;
	int		flag;

	flag = FALSE;
	check_eof(input);
	if (input[0] == '\0' || is_all_blank(input))
		return (FALSE);
	aux = ft_strtrim(input, " \t");
	temp = clean_quotes(tokenizer(aux));
	if (!temp[1] && is_all_dollar(temp[0]))
		flag = TRUE;
	free(aux);
	ft_free_matrix(temp);
	if (g_var.invalid_input || flag)
		return (FALSE);
	return (TRUE);
}

void	run_prompt(char **envp)
{
	char	*aux;

	g_var.envp = dup_envp(envp);
	g_var.exit_code = 0;
	initial_message();
	while (1)
	{
		init_gvar_data();
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		aux = readline(g_var.prompt_line);
		if (is_valid_input(aux))
		{
			g_var.input = ft_strtrim(aux, " \t");
			exec_args();
		}
		if (g_var.input)
			free(g_var.input);
		free(aux);
		free(g_var.prompt_line);
	}
}

// include in utils

void	ft_free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		ft_free_ptr((void *)&matrix[i]);
		i++;
	}
	ft_free_ptr((void *)&matrix);
}

int	ft_chrpos(char *s, int c)
{
	int				i;
	unsigned char	*temp;
	unsigned char	temp_c;

	i = 0;
	temp = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (temp[i] != '\0')
	{
		if (temp[i] == temp_c)
			return (i);
		i++;
	}
	if (temp_c == '\0')
		return (-1);
	return (-1);
}
