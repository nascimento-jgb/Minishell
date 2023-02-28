/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:43:16 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/28 12:47:40 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	new_pipe(int bol_output)
{
	int	new_pipe[2];

	dup2(g_var.old_pipe_in, STDIN_FILENO);
	if (g_var.old_pipe_in != 0)
		close(g_var.old_pipe_in);
	if (!bol_output)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	g_var.old_pipe_in = dup(new_pipe[IN]);
	close(new_pipe[IN]);
}

static void	save_actual_fd(void)
{
	g_var.actual_fd[IN] = dup(STDIN_FILENO);
	g_var.actual_fd[OUT] = dup(STDOUT_FILENO);
}

static void	save_history(char **args)
{
	char	*input;

	if (is_all_valid_history(g_var.input))
	{
		input = ft_matrix_to_str(args);
		add_history(input);
		free(input);
	}
}

void	pipe_checker(void)
{
	char	**args;
	int		i;

	i = 0;
	args = pipe_args();
	save_history(args);
	while (args[i] && !g_var.invalid_input)
	{
		if (args[i + 1] && args[i + 1][0] == '|')
		{
			save_actual_fd();
			new_pipe(TRUE);
		}
		else
		{
			new_pipe(FALSE);
			g_var.close_code = TRUE;
		}
		execute_general(&args[i]);
		change_fd(g_var.actual_fd);
		if (args[++i] && args[i][0] == '|')
			i++;
	}
	ft_free_matrix(args);
}
