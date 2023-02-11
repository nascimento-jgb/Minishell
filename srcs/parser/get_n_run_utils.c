/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_run_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:47:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/11 13:21:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	run_pipe(t_pipecmd *pipe_cmd, t_command *cmd, int p[], t_minishell *minishell)
{
	pipe_cmd = (t_pipecmd *)cmd;
	if (pipe(p) < 0)
		exit_message("Error.\n");
	if (fork_create() == 0)
	{
		close(1);
		dup(p[1]);
		close(p[0]);
		close(p[1]);
		run_command(pipe_cmd->left, minishell);
	}
	if (fork_create() == 0)
	{
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		run_command(pipe_cmd->right, minishell);
	}
	close(p[0]);
	close(p[1]);
	wait(NULL);
	wait(NULL);
}

void	run_redirect(t_redirectcmd	*redir_cmd, t_command *cmd, t_minishell *minishell)
{
	redir_cmd = (t_redirectcmd *)cmd;
	close(redir_cmd->fd);
	if (open(redir_cmd->file, redir_cmd->mode) < 0)
		exit_message("Filed to open file.\n");
	run_command(redir_cmd->cmd, minishell);
}

void	run_andoperator(t_andcmd *and_operator, t_command *cmd, t_minishell *minishell)
{
	and_operator = (t_andcmd *)cmd;
	if (fork_create() == 0)
		run_command(and_operator->cmd, minishell);
}

void	run_exec(t_execcmd *exec_cmd, t_command *cmd, t_minishell *minishell)
{
	char **env_arr;
	// int i = 0;

	env_arr = env_to_arr(minishell);
	if (!env_arr)
		return ;
	exec_cmd = (t_execcmd *)cmd;
	if (exec_cmd->argv[0] == 0)
		exit(1);
	// while (env_arr[i])
	// 	ft_printf("%s\n", env_arr[i++]);
	minishell->paths = check_path(env_arr);
	minishell->cmd_paths = ft_split(minishell->paths, ':');
	minishell->cmd_args = ft_split(exec_cmd->argv[0], ' ');
	minishell->cmd = get_command(minishell->cmd_paths, minishell->cmd_args[0]);
	if (execve(minishell->cmd, exec_cmd->argv, env_arr) == -1)
		exit_message("execve() failed\n");
}

void	run_line(t_linecmd *line_cmd, t_command *cmd, t_minishell *minishell)
{
	line_cmd = (t_linecmd *)cmd;
	if (fork_create() == 0)
		run_command(line_cmd->left, minishell);
	wait(NULL);
	run_command(line_cmd->right, minishell);
}

// auxiliar functions from pipex

char	*check_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*get_command(char **paths, char *cmd)
{
	char	*aux;
	char	*command;

	while (*paths)
	{
		aux = ft_strjoin(*paths, "/");
		command = ft_strjoin(aux, cmd);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}
