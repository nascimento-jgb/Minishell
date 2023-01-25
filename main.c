/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 15:44:02 by andrferr         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	char	**array;
	int	fd;

	if (argc < 2)
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
	}
	return (0);
}
