/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arguments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:54:01 by jonascim          #+#    #+#             */
/*   Updated: 2023/01/24 11:00:41 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

char	get_input(int argc, char **argv)
{
	char	**str;

	if (argc == 2)
		str = get_one_arg(argv);
	else
		str = get_multiple_arg(argc, argv);
	return (str);
}

static char	**get_one_arg(char **argv)
{
	char	**str;

	str = ft_split(argv[1], ' ');
	if (!str || str[0] == NULL)
		exit_message("Input reading error.\n");
	return (str);
}

static char **get_multiple_arg(int argc, char **argv)
{
	char	**str;
	int		i;

	i = 0;
	str = malloc(sizeof(char *) * argc);
	if (!str)
		ext_message("Malloc error.\n");
	while (argv[i + 1])
	{
		str[i] = ft_strdup(argv[i + 1]);
		if (!str[i])
		{
			free(str); //copy ft_free_char_array from my libft and use it here
			exit("Allocation error.\n");
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}
