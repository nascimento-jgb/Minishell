/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:43:35 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 15:36:14 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_message(char *error)
{
	ft_putstr_fd(error, 2);
	exit(1);
}

void	blt_error_msg(char *cmd, int err, char *path)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(err), 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd(path, 2);
}
