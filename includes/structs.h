/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:44:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/29 14:43:49 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vars
{
	char			*key;
	char			*value;
	char			*path;
	struct s_vars	*next;
}	t_vars;

typedef struct s_env
{
	t_vars	*vars_list;
	int		total_env_vars;
}	t_env;

typedef struct s_minishell
{
	t_env	*env;
	int		argc;
	char	**argv;
}	t_minishell;

#endif