/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:22:09 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/25 14:36:56 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect_error_msg(char **args)
{
	if (!g_var.error)
	{
		g_var.exit_code = 2;
		g_var.invalid_input = TRUE;
		ft_putendl_fd("Redirect: syntax error", STDERR_FILENO);
		if (args)
			ft_free_matrix(args);
		exit_prompt();
	}
}

static void	pipe_error_msg(t_list **lst)
{
	if (!g_var.invalid_input)
	{
		g_var.error = TRUE;
		g_var.exit_code = 2;
		g_var.invalid_input = TRUE;
		ft_putendl_fd("Syntax error: unexpected end of file", STDERR_FILENO);
		if (lst)
			ft_lstclear(lst, free);
		exit_prompt();
	}
}

void	continue_add_pipe_arg(t_list **lst)
{
	char	*input;
	char	*aux;

	input = readline("> ");
	if (!input || !g_var.invalid_input)
		pipe_error_msg(lst);
	else
	{
		aux = ft_strtrim(input, " \t");
		if (aux[ft_strlen(aux) - 1] == '|')
		{
			ft_lstadd_back(lst, ft_lstnew(ft_substr(aux, 0,
						ft_chrpos(aux, '|') - 1)));
			ft_lstadd_back(lst, ft_lstnew(ft_strdup("|")));
			continue_add_pipe_arg(lst);
		}
		else
			ft_lstadd_back(lst, ft_lstnew(ft_strdup(aux)));
		free(aux);
		free(input);
	}
}
