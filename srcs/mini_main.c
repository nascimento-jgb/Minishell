/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:28:43 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/20 08:35:09 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/minishell.h"

t_helper	g_var;

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1 && argv)
		return (1);
	run_prompt(envp);
	return (0);
}
