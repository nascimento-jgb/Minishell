/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:43:19 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:45:17 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	here_doc_error_msg(char *eof)
{
	ft_putstr_fd("warning: here-document delimited by end-of-file (wanted `",
		STDERR_FILENO);
	ft_putstr_fd(eof, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
}

static void	get_input(int temp_file, char *eof)
{
	char	*input;

	input = readline("> ");
	if (!input && !g_var.invalid_input)
		here_doc_error_msg(eof);
	else
	{
		while (input && (ft_memcmp(input, eof, ft_strlen(input)) != 0
				|| ft_memcmp(input, eof, ft_strlen(eof)) != 0))
		{
			if (input[0] == '\0')
				ft_putendl_fd("", temp_file);
			else
				ft_putendl_fd(input, temp_file);
			g_var.exit_code = 0;
			free(input);
			input = readline("> ");
			if (!input && !g_var.invalid_input)
				here_doc_error_msg(eof);
		}
		if (input)
			free(input);
	}
}

void	here_doc(char *eof)
{
	int	temp_file;
	int	actual_fd_out;

	temp_file = open("temp_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (temp_file == -1)
	{
		g_var.error = TRUE;
		g_var.exit_code = 9;
		return ;
	}
	actual_fd_out = dup(STDOUT_FILENO);
	dup2(g_var.initial_fd[OUT], STDOUT_FILENO);
	signal(SIGINT, here_doc_stop);
	signal(SIGQUIT, SIG_IGN);
	get_input(temp_file, eof);
	close(temp_file);
	change_input("temp_file", O_RDONLY);
	unlink("temp_file");
	dup2(actual_fd_out, STDOUT_FILENO);
	close(actual_fd_out);
}
