/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/25 17:30:53 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*tmp_join(char *str1, char *str2)
{
	char *tmp;
	tmp = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (tmp);
}

char	*get_dir(void)
{
	char	*username;
	char	*dir;
	char	*prompt;
	
	username = ft_strdup(getenv("USER"));
	if (!username)
		return (NULL);
	username = tmp_join(ft_strdup("@"), username);
	if (!username)
		return (NULL);
	username = tmp_join(username, ft_strdup(":"));
	if (!username)
		return (NULL);
	dir = (char *)malloc(sizeof(char) * 1024);
	if (!dir)
	{
		ft_strdel(&username);
		return (NULL);
	}
	getcwd(dir, 1024);
	prompt = tmp_join(username, dir);
	if (!prompt)
	{
		ft_strdel(&username);
		ft_strdel(&dir);
		return (0);
	}
	prompt = tmp_join(prompt, ft_strdup("$ "));
	return (prompt);
}