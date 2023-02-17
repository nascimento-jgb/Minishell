/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:57:34 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/17 16:38:53 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	quotes_stage(char *str, int index)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (str[i] && i <= index)
	{
		if (i > 0 && str[i - 1] == '\\')
			;
		else if (open == 0 && str[i] == '\"')
			open = 1;
		else if (open == 0 && str[i] == '\'')
			open = 2;
		else if (open == 1 && str[i] == '\"')
			open = 0;
		else if (open == 2 && str[i] == '\'')
			open = 0;
		i++;
	}
	return (open);
}
