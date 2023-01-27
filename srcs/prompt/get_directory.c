/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/27 14:05:41 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*tmp_join(char *str1, char *str2)
{
	char *tmp;
	tmp = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (tmp);
}

static char *filter_dir(char *username)
{
	char	*dir;
	char	*final_dir;
	int		i;
	dir = (char *)malloc(sizeof(char) * 1024);
	if (!dir)
		return (NULL);
	getcwd(dir, 1024);
	i = 0;
	while (ft_strncmp(&dir[i], username, ft_strlen(username)))
		i++;
	i += ft_strlen(username);
	final_dir = ft_strdup(&dir[i]);
	if (!final_dir)
	{
		free(dir);
		return (NULL);
	}
	free(dir);
	final_dir = tmp_join( ft_strdup("~"), final_dir);
	return (final_dir);
}

char	*get_dir(void)
{
	char	*username;
	char	*dir;
	char	*prompt;

	username = ft_strdup(getenv("USER"));
	if (!username)
		return (NULL);
	dir = filter_dir(username);
	if (!dir)
	{
		free(username);
		return (NULL);
	}
	username = tmp_join(ft_strdup("\33[31m@"), username);
	if (!username)
	{
		free(dir);
		return (NULL);
	}
	username = tmp_join(username, ft_strdup(":\33[0m"));
	if (!username)
	{
		free(dir);
		return (NULL);
	}
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
