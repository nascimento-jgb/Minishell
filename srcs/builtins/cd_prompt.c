/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:18:11 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/22 17:02:10 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_cwd(void)
{
	char	*export_pwd;
	char	*buffer;
	char	*pwd;

	buffer = NULL;
	pwd = getcwd(buffer, 0);
	export_pwd = ft_strjoin("export PWD=", pwd);
	free(pwd);
	return (export_pwd);
}

static void	try_chdir(char *path, char *old_pwd)
{
	char	*export_pwd;
	char	*export_old_pwd;
	char	**to_export;

	if (chdir(path) == 0)
	{
		export_pwd = get_cwd();
		export_old_pwd = ft_strjoin("export OLDPWD=", old_pwd);
		to_export = tokenizer(export_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		to_export = tokenizer(export_old_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		free(export_pwd);
		free(export_old_pwd);
	}
	else
	{
		ft_putstr_fd("cd: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
		g_var.exit_code = 1;
	}
}

static void	to_old_chdir(char *old_pwd, char *pwd)
{
	char	*export_pwd;
	char	*export_old_pwd;
	char	**to_export;

	if (chdir(old_pwd) == 0)
	{
		export_pwd = ft_strjoin("export PWD=", old_pwd);
		export_old_pwd = ft_strjoin("export OLDPWD=", pwd);
		to_export = tokenizer(export_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		to_export = tokenizer(export_old_pwd);
		export_prompt(to_export);
		ft_free_matrix(to_export);
		free(export_pwd);
		free(export_old_pwd);
	}
	else
	{
		ft_putendl_fd("cd: OLDPWD not set", STDERR_FILENO);
		g_var.exit_code = TRUE;
	}
}

static void	exec_cd(char **args, char **home, char **pwd, char **old_pwd)
{
	char	*aux;

	if (args[1][0] == '/')
		try_chdir(args[1], pwd[0]);
	else if (ft_memcmp(args[1], "-", ft_strlen(args[1])) == 0
		&& ft_memcmp(args[1], "-", 1) == 0)
		to_old_chdir(old_pwd[0], pwd[0]);
	else if (args[1][0] == '~')
	{
		aux = ft_strjoin(home[0], args[1] + 1);
		if (ft_strlen(args[1]) > 1)
			try_chdir(aux, pwd[0]);
		else
			try_chdir(home[0], pwd[0]);
		free(aux);
	}
	else
		try_chdir(args[1], pwd[0]);
}

void	cd_prompt(char **args)
{
	char	**home;
	char	**pwd;
	char	**old_pwd;

	if (g_var.args_num > 2)
	{
		printf("cd: too many arguments\n");
		g_var.error++;
		g_var.exit_code = TRUE;
	}
	pwd = replace_env_var(tokenizer("$PWD"));
	old_pwd = replace_env_var(tokenizer("$OLDPWD"));
	home = replace_env_var(tokenizer("$HOME"));
	exec_cd(args, home, pwd, old_pwd);
	ft_free_matrix(home);
	ft_free_matrix(pwd);
	ft_free_matrix(old_pwd);
}
