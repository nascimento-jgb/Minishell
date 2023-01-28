/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrferr <andrferr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:44:56 by andrferr          #+#    #+#             */
/*   Updated: 2023/01/28 11:21:20 by andrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_env
{
	t_list	*env_list;
	int		total_env_vars;
}	t_env;

typedef struct s_vars
{
	t_list	*vars_list;
	int	total_vars;
}	t_vars;

typedef struct s_minishell
{
	t_env	*env;
	t_vars	*vars;
	int		argc;
	char	**argv;
}	t_minishell;

#endif