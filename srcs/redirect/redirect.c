/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:46:13 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 16:41:19 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	special_case_fd(char *file, char *redirect)
{
	int	fd;

	if (ft_memcmp(redirect, "<<>", 3) == 0 || ft_memcmp(redirect, "><", 2) == 0)
	{
		g_var.error = TRUE;
		g_var.exit_code = 2;
		change_fd(g_var.initial_fd);
		ft_putendl_fd("Redirect: syntax error near unexpected token `<'",
			STDERR_FILENO);
	}
	else if (ft_memcmp(redirect, "<>>", 3) == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
		close(fd);
		change_input(file, O_RDONLY);
	}
	else if (ft_memcmp(redirect, "<>", 2) == 0)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		close(fd);
		change_input(file, O_RDONLY);
	}
}

static void	exec_redirect(char *redirect, char *file)
{
	if (ft_memcmp(redirect, "<<>", 3) == 0
		|| ft_memcmp(redirect, "<>>", 3) == 0
		|| ft_memcmp(redirect, "<>", 2) == 0
		|| ft_memcmp(redirect, "><", 2) == 0)
		special_case_fd(file, redirect);
	else if (ft_memcmp(redirect, ">>", 2) == 0)
		change_output(file, O_WRONLY | O_CREAT | O_APPEND);
	else if (ft_memcmp(redirect, "<<", 2) == 0)
		here_doc(file);
	else if (ft_memcmp(redirect, ">", 2) == 0)
		change_output(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (ft_memcmp(redirect, "<", 2) == 0)
		change_input(file, O_RDONLY);
}

static int	is_valid_redirection(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_chrqty(args[i], '>') > 0 || ft_chrqty(args[i], '<') > 0)
		{
			if ((args[i][0] == '>' || args[i][0] == '<') &&
				((ft_chrqty(args[i], '>') > 2 || ft_chrqty(args[i], '<') > 2)
				|| (!args[i + 1] || ft_chrqty(args[i + 1], '>') > 0
					|| ft_chrqty(args[i + 1], '<') > 0)))
			{
				g_var.exit_code = 2;
				return (FALSE);
			}
		}
		i++;
	}
	return (TRUE);
}

void	redirect(char **input)
{
	int		i;
	char	**args;

	args = redirect_args(replace_env_var(tokenizer(*input)));
	if (!is_valid_redirection(args))
	{
		g_var.error = TRUE;
		ft_putendl_fd("Redirect: syntax error", STDERR_FILENO);
	}
	else
	{
		i = 0;
		while (args[i] && args[i + 1])
		{
			exec_redirect(args[i], args[i + 1]);
			i++;
		}
		redirect_input_cleaning(args, input);
	}
	ft_free_matrix(args);
}
