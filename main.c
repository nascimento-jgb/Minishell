/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 15:27:33 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	exit_message(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

int	fork_create(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		exit_message("Fork error.\n");
	return (pid);
}

char	*get_cmd_line(char *line)
{
	if (line)
	{
		free(line);
		line = (char *)NULL;
	}
	line = readline("$ ");
}

int	main(int argc, char **argv)
{
	// char	**array;
	// // int	fd;
	static char *line_read;

	(void)argc;
	(void)argv;
	line_read = (char *)NULL;
	// if (argc < 2)
	// 	exit_message("Invalid input.\n");
	// else
	// 	array = get_input(argc, argv);

	// while ((fd = open("console", O_RDWR)) >= 0)
	// {
	// 	if (fd >=3)
	// 	{
	// 		close(fd);
	// 		break ;
	// 	}
	// }
	line_read = get_cmd_line(line_read);
	free(line_read);
	return (0);
}
