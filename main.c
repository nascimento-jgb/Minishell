/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:33:12 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/20 13:25:10 by andrferr         ###   ########.fr       */
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
		line = (char *) NULL;
	}
	line = readline("$ ");
	return (line);
}

/*int	main(int argc, char **argv, char **env)
{
	//t_minishell	*minishell;

	int i = -1;
		while (argv[++i])
			ft_printf("%s\n", argv[i]);
		ft_printf("argc: %d\n", argc);
	(void)argc;
	(void)argv;
	minishell = minishell_init(env);
	if (!minishell)
		return (1);
	open_shell();
	prompt(minishell);
	clean_minishell(minishell);
	return (0);
}*/
