/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:29:57 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/10 18:00:26 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	|		returns		|
	(		returns		(
	)		returns		)
	<		returns		<
	<<		returns		-
	>		returns		>
	>>		returns		+
	&		returns		&
	&&		returns		=
	;		returns		;
	(end)	returns		0
	others	returns		a
*/

// edit this functions as a pointer to function
int	check_tokken(char *scan, char *end_scan, char *spaces, char *symbols)
{
	int	res;

	if (*scan == 0)
		res = 0;
	else if (*scan == '|')
	{
		res = '|';
		scan++;
	}
	else if (*scan == '(')
	{
		res = '(';
		scan++;
	}
	else if (*scan == ')')
	{
		res = ')';
		scan++;
	}
	else if (*scan == '>')
	{
		res = '>';
		scan++;
		if (*scan == '>')
		{
			res = '+';
			scan++;
		}
	}
	else if (*scan == '<')
	{
		res = '<';
		scan++;
		if (*scan == '<')
		{
			res = '-';
			scan++;
		}
	}
	else if (*scan++ == '&')
	{
		res = '&';
		scan++;
		if (*scan == '&')
		{
			res = '=';
			scan++;
		}
	}
	else if (*scan++ == ';')
	{
		res = ';';
		scan++;
	}
	else
		res = 'a';
	while (scan < end_scan && !ft_strchr(spaces, *scan) && !ft_strchr(symbols, *scan))
		scan++;
	return (res);
}

int	skip_to(char **ptr_scan, char *end_scan, char *tokken)
{
	char	spaces[] = " \t\r\n\v";
	char	*scan;

	scan = *ptr_scan;
	while (scan < end_scan && ft_strchr(spaces, *scan))
		scan++;
	*ptr_scan = scan;
	return (*scan && ft_strchr(tokken, *scan));
}

int	get_tokken(char **ptr_scan, char *end_scan, char **tkn, char **end_tkn)
{
	char	spaces[] = " \t\r\n\v";
	char	symbols[] = "<|>&();";
	char	*scan;
	int		ret;

	scan = *ptr_scan;
	while (scan < end_scan && !ft_strchr(spaces, *scan))
		scan++;
	if (tkn)
		*tkn = scan;
	ret = *scan;
	//include all possible cases in a different function
	ret = check_tokken(scan, end_scan, spaces, symbols);
	//possible cases above
	if (end_tkn)
		*end_tkn = scan;
	while (scan < end_scan && ft_strchr(spaces, *scan))
		scan++;
	*ptr_scan = scan;
	return (ret);
}

t_command	*null_terminate(t_command *cmd)
{
	t_execcmd		*exec_cmd;
	t_pipecmd		*pipe_cmd;
	t_redirectcmd	*redir_cmd;
	t_andcmd		*and_cmd;
	t_linecmd		*line_cmd;
	int				i;

	i = 0;
	if (cmd == 0)
		return (0);
	if (cmd->command_type == PIPE)
	{
		pipe_cmd = (t_pipecmd *)cmd;
		null_terminate(pipe_cmd->left);
		null_terminate(pipe_cmd->right);
	}
	if (cmd->command_type == REDIRECT)
	{
		redir_cmd = (t_redirectcmd *)cmd;
		null_terminate(redir_cmd->cmd);
		*redir_cmd->exit_file = 0;
	}
	if (cmd->command_type == EXEC)
	{
		exec_cmd = (t_execcmd *)cmd;
		while (exec_cmd->argv[i])
			exec_cmd->eargv[i++] = 0;
	}
	if (cmd->command_type == OPERATORAND)
	{
		and_cmd = (t_andcmd *)cmd;
		null_terminate(and_cmd->cmd);
	}
	if (cmd->command_type == LINE)
	{
		line_cmd = (t_linecmd *)cmd;
		null_terminate(line_cmd->left);
		null_terminate(line_cmd->right);
	}
	return (cmd);
}
