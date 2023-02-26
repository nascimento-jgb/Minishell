/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:08:15 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/26 16:12:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_exit_cmd(void)
{
	int		result;
	char	**cmds;

	result = FALSE;
	cmds = ft_split(g_var.input, ' ');
	if (cmds)
	{
		if ((ft_memcmp(cmds[0], "exit", ft_strlen(cmds[0])) == 0
				&& ft_memcmp(cmds[0], "exit", 4) == 0))
			result = TRUE;
	}
	ft_free_matrix(cmds);
	return (result);
}

int	is_builtin(char **args)
{
	if (!g_var.error && args[0])
	{
		if (ft_memcmp(args[0], "exit", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "exit", 4) == 0)
			return (1);
		if (ft_memcmp(args[0], "pwd", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "pwd", 3) == 0)
			return (2);
		if (ft_memcmp(args[0], "echo", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "echo", 4) == 0)
			return (3);
		if (ft_memcmp(args[0], "env", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "env", 3) == 0)
			return (4);
		if (ft_memcmp(args[0], "export", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "export", 6) == 0)
			return (5);
		if (ft_memcmp(args[0], "unset", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "unset", 5) == 0)
			return (6);
		if (ft_memcmp(args[0], "cd", ft_strlen(args[0])) == 0
			&& ft_memcmp(args[0], "cd", 2) == 0)
			return (7);
	}
	return (FALSE);
}
