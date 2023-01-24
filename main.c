/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/24 10:56:19 by jonascim         ###   ########.fr       */
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
