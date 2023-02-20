/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:10:20 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/19 15:19:02 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	export_error_msg(char *arg, int return_code)
{
	ft_putstr_fd("export '", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
	g_var.exit_code = 1;
	return (return_code);
}

int	is_valid_attribution(char *arg, char *next)
{
	int	i;
	int	j;

	i = 0;
	j = ft_chrpos(arg, '=');
	if (j == -1)
		return (0);
	if (j == 0)
		return (export_error_msg(arg, FALSE));
	while (i < j)
	{
		if (!(ft_isalpha(arg[i]) || ft_isdigit(arg[i]))
			|| is_all_digit(arg, j))
			return (export_error_msg(arg, FALSE));
		i++;
	}
	if (!arg[j + 1] && next)
		return (export_error_msg(next, -1));
	return (TRUE);
}
