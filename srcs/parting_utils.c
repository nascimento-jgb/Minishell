/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:29:59 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/03 11:26:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_command *parse_command(char *scan)
{
	char *end_scan;
	t_command *cmd;

	end_scan = scan + ft_strlen(scan);
	cmd = parse_line(&scan, end_scan);
	skip_to_tokken(&scan, end_scan, "");
	if (scan != end_scan)
		exit_message("Syntax error.\n");
	null_terminate(cmd);
	return (cmd);
}

t_command parse_line(char **ptr_scan, char *end_scan)
{
	t_command *cmd;

}
