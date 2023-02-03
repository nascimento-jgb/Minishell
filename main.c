/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/03 11:26:01 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"


int	fork_create(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit_message("Fork error.\n");
	else
		return (pid);
	return (0);
}

char	*get_cmd_line(char *line)
{
	if (line)
	{
		free(line);
		line = (char *)NULL;
	}
	line = readline("$ ");
	return (line);
}

void	opening_files(void)
{
	int	fd;

	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}
}

int	main(int argc, char **argv)
{
	// char	**array;
	// // int	fd;
	static char *line_read;

	(void)argc;
	(void)argv;
	line_read = (char *)NULL;

	opening_files();
	open_shell();
	prompt();
	line_read = get_cmd_line(line_read);
	free(line_read);
	return (0);
}
