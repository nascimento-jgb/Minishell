/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:41:32 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/17 16:56:44 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_argc(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (((!ft_isspace(str[i]) && ft_isspace(str[i + 1])) || (!ft_isspace(str[i]) && str[i + 1] == '\0')) && !quotes_stage(str, i))
			count++;
		i++;
	}
	ft_printf("argc: %d\n", count);
	return (count);
}

int argv_parser(t_minishell *minishell)
{
	char	**argv;
	char	*str;
	int		i;
	int		j;
	int		k;
	str = minishell->capturedLine;
	if (quotes_stage(str, 2147483647))
	{
		ft_putendl_fd("Please close the quotes", 2);
		return (1);
	}
	minishell->argc = count_argc(minishell->capturedLine);
	argv = ft_calloc(minishell->argc + 1, sizeof(char *));
	if (!argv)
		return (0);
	i = 0;
	while (*str && i < minishell->argc)
	{
		j = 0;
		while (ft_isspace(*str))
			str++;
		k = 0;
		ft_printf("str: %s\n", str);
		while (!ft_isspace(*str) && !quotes_stage(str, k))
		{
			if (*(str + k) == 34)
				k++;
			else
			{
				write(1, "#", 1);
				argv[i][j++] = *(str + k);
			}
			k++;
		}
		i++;
	}
	argv[i] = NULL;
	minishell->argv = argv;
	return (0);
}
