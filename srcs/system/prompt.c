/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:00 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/21 15:03:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execute_general(char **input)
{
	int		code;
	char	**args;

	redirect(input);
	args = clean_quotes(replace_env_var(tokenizer(*input)));
	if (!g_var.error && args[0])
	{
		code = is_builtin(args);
		if (code)
			exec_builtin(args, code);
		else
			exec_cmd(redirect_args(args));
	}
}

static void	exec_args(void)
{
	if (!is_exit_cmd())
	{
		// printf("HEY7\n");
		save_fd(g_var.initial_fd);
		// printf("%d\n", g_var.initial_fd[0]);
		g_var.old_pipe_in = 0;
		// printf("HEY8\n"); All okay
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
	if (input[0] == '\0')
		return (FALSE);
	if (is_all_blank(input))
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


	// printf("HEY1\n");
	// printf("%s\n", envp[0]);
	g_var.envp = envp_dup(envp);
	// printf("%s\n", g_var.envp[0]);
	// printf("HEY3\n");
	g_var.exit_code = 0;
	initial_message();
	while (TRUE)
	{

		init_gvar_data();
		// int i = 0;
		// while (g_var.envp[i])
		// 	printf("%s\n", g_var.envp[i++]); //OKAY
		signal(SIGINT, new_prompt);
		signal(SIGQUIT, SIG_IGN);
		aux = readline(g_var.prompt_line);
		// printf("%s\n", aux); OKAY
		if (is_valid_input(aux))
		{
			// printf("HEY5\n");
			g_var.input = ft_strtrim(aux, " \t");
			// printf("%s\n", g_var.input);
			// printf("HEY6\n"); OKAY
			exec_args();
		}
		if (g_var.input)
			free(g_var.input);
		free(aux);
		free(g_var.prompt_line);
	}
}
