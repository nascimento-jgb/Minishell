/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:14:05 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 16:07:13 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin(char **args, int code)
{
	if (code == 1)
	{
		ft_free_matrix(args);
		exit_prompt();
	}
	if (code == 2)
		pwd_prompt();
	if (code == 3)
		echo_prompt(args);
	if (code == 4)
		env_prompt();
	if (code == 5)
		export_prompt(args);
	if (code == 6)
		unset_prompt(args);
	if (code == 7)
		cd_prompt(args);
}
