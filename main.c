/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 17:34:02 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

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

int	main(int argc, char **argv)
{
	//char	**array;
	//int	fd;
	ft_printf("%d %s\n", argc, argv[0]);
	/*if (argc < 2)
		error_message("invalid input.\n");
	else
		array = get_input(argc, argv);
	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >=3)
		{
			close(fd);
			break ;
		}
	}*/
	open_shell();
	while (1)
	{
		char	*a;
		char	*dir;

		dir = get_dir();
		if (!dir)
			return (1);
		a = readline(dir);
		if (!a)
		{
			free(dir);
			return (0);
		}
		add_history(a);
		ft_printf("\na: %s\n", a);
		ft_strdel(&dir);
		ft_strdel(&a);
	}
	rl_clear_history();
	return (0);
}
