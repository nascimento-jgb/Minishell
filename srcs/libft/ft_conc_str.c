/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conc_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:34:51 by andrferr          #+#    #+#             */
/*   Updated: 2023/02/22 17:35:46 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_conc_str(char **result, char *str)
{
	char	*temp;
	char	*aux;

	temp = ft_strjoin(" ", str);
	aux = ft_strjoin(*result, temp);
	free(*result);
	*result = ft_strdup(aux);
	free(temp);
	free(aux);
}
