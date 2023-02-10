/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:29:59 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/10 16:34:38 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_command	*parse_command(char *scan)
{
	char		*end_scan;
	t_command	*cmd;

	end_scan = scan + ft_strlen(scan);
	cmd = parse_line(&scan, end_scan);
	skip_to(&scan, end_scan, "");
	if (scan != end_scan)
		exit_message("Syntax error.\n");
	null_terminate(cmd);
	return (cmd);
}

t_command	*parse_line(char **ptr_scan, char *end_scan)
{
	t_command	*cmd;

	cmd = parse_pipe(ptr_scan, end_scan);
	while (skip_to(ptr_scan, end_scan, "&"))
	{
		get_tokken(ptr_scan, end_scan, 0, 0);
		cmd = and_cmd_init(cmd);
	}
	if (skip_to(ptr_scan, end_scan, ";"))
	{
		get_tokken(ptr_scan, end_scan, 0, 0);
		cmd = line_cmd_init(cmd, parse_line(ptr_scan, end_scan));
	}
	return (cmd);
}

t_command	*parse_pipe(char **ptr_scan, char *end_scan)
{
	t_command	*cmd;

	cmd =  parse_exec(ptr_scan, end_scan);
	if (skip_to(ptr_scan, end_scan, "|"))
	{
		get_tokken(ptr_scan, end_scan, 0, 0);
		cmd = pipe_cmd_init(cmd, parse_pipe(ptr_scan, end_scan));
	}
	return (cmd);
}

t_command	*parse_redir(t_command *cmd, char **ptr_scan, char *end_scan)
{
	char	*tokken;
	char	*end_tokken;
	int		aux_tokken;

	while (skip_to(ptr_scan, end_scan, "<>"))
	{
		aux_tokken = get_tokken(ptr_scan, end_scan, 0, 0);
		if (get_tokken(ptr_scan, end_scan, &tokken, &end_tokken) != 'a')
			exit_message(" Error - missing file for redirection.\n");
		if (aux_tokken == '<' || aux_tokken == '-') // redirections must be checked - means <<
			cmd = redirect_cmd_init(cmd, tokken, end_tokken, O_RDONLY, 0);
		else if (aux_tokken == '>' || aux_tokken == '+') // redirections must be checked
			cmd = redirect_cmd_init(cmd, tokken, end_tokken, O_WRONLY | O_CREAT, 0);
	}
	return (cmd);
}

t_command	*parse_parenthesis(char **ptr_scan, char *end_scan)
{
	t_command	*cmd;

	if (!skip_to(ptr_scan, end_scan, "("))
		exit_message("parse_parathesis() error.\n");
	get_tokken(ptr_scan, end_scan, 0, 0);
	cmd = parse_line(ptr_scan, end_scan);
	if (!skip_to(ptr_scan, end_scan, ")"))
		exit_message("syntax error - missing ) .\n");
	get_tokken(ptr_scan, end_scan, 0, 0);
	cmd = parse_redir(cmd, ptr_scan, end_scan);
	return (cmd);
}

t_command	*parse_exec(char **ptr_scan, char *end_scan)
{
	char	*tokken;
	char	*end_tokken;
	int		aux_tokken;
	int		argc = 0;
	t_execcmd	*cmd;
	t_command	*ret;

	if (skip_to(ptr_scan, end_scan, "("))
		return (parse_parenthesis(ptr_scan, end_scan));
	ret = exec_cmd_init();
	cmd = (t_execcmd *)ret;
	ret = parse_redir(ret, ptr_scan, end_scan);
	while (!skip_to(ptr_scan, end_scan, "|)&;"))
	{
		if ((aux_tokken = get_tokken(ptr_scan, end_scan, &tokken, &end_tokken)) == 0)
			break;
		if (aux_tokken != 'a')
			exit_message("Syntax error indetified.\n");
		cmd->argv[argc] = tokken;
		cmd->eargv[argc] = end_tokken;
		argc++;
		printf("%d - %d\n", argc, aux_tokken);
		if (argc >= MAXARGS)
			exit_message("Too many arguments.\n");
		ret = parse_redir(ret, ptr_scan, end_scan);
	}
	cmd->argv[argc] = 0;
	cmd->eargv[argc] = 0;
	return (ret);
}
