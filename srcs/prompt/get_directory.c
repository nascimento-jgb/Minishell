/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:49 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/30 11:19:48 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*tmp_join(char *str1, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(str1, str2);
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (tmp);
}

char	*add_color(char *color, char *str)
{
	char	*tmp;

	tmp = tmp_join(color, str);
	if (!tmp)
		return (0);
	tmp = tmp_join(tmp, ft_strdup(":\33[0m"));
	if (!tmp)
		return (0);
	return (tmp);
}

static char	*filter_dir(char *username)
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
	final_dir = tmp_join(ft_strdup("~"), final_dir);
	if (!final_dir)
		return (0);
	final_dir = add_color(ft_strdup("\033[92m"), final_dir);
	return (final_dir);
}

static char	*final_prompt(char *username, char *dir)
{
	char	*prompt;

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
	username = add_color(ft_strdup("\33[31m@"), username);
	if (!username)
	{
		free(dir);
		return (NULL);
	}
	prompt = final_prompt(username, dir);
	return (prompt);
}
