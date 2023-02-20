/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:20:23 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 14:31:34 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_flag(char **args)
{
	int	flag;

	if (g_var.args_num > 1 && args[1])
	{
		flag = ft_memcmp(args[1], "-n", ft_strlen(args[1])) + ft_memcmp(args[1], "-n", 2);
		if (flag)
			flag = ft_memcmp(args[1], "-n ", ft_strlen(args[1])) + ft_memcmp(args[1], "-n ", 2);
		if (!flag && g_var.args_num > 2 && !(args[1][2] == SPACE_VALUE || args[2][0] == SPACE_VALUE))
			flag = TRUE;
	}
	else
		flag = TRUE;
	return (flag);
}

void	echo_prompt(char **args)
{
	int		i;
	int		flag;

	flag = get_flag(args);
	if (!flag)
		i = 2;
	else
		i = 1;
	while (g_var.args_num > 1 && args[i])
	{
		if (i == 2 && !flag && g_var.args_num > 2 && args[2][0] == SPACE_VALUE)
			printf("%s", args[i] + 1);
		else
			printf("%s", args[i]);
		i++;
	}
	if (g_var.args_num >= 1 && flag)
		printf("\n");
	g_var.exit_code = 0;
}
