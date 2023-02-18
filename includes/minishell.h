/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:39:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/18 16:46:55 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// DEFINES
# define IN				0
# define OUT			1
# define FALSE			0
# define TRUE			1
# define SPACE_VALUE	32
# define DOUBLE_QUOTES	34
# define DOLLAR_SIGN	36
# define SINGLE_QUOTES	39

// STRUCT
typedef struct s_helper
{
	int		args_num;
	int		error;
	int		exit_code;
	int		close_code;
	int		old_pipe_in;
	int		invalid_input;
	int		initial_fd[2];
	int		actual_fd[2];
	char	*input;
	char	*prompt_line;
	char	**envp;
}	t_helper;

// GLOBAL VARIABLE

extern t_helper	g_var;

// FUNTIONS -
// SYSTEM
char		**dup_env(char **envp);
void		init_gvar_data(void);
void		initial_message(void);
void		check_eof(char *input);

// TOKENIZER
char		**tokenizer(char *input);
int			increment_quotes(int i, char *input);
int			increment_count(int i, int c, char *input);
void		split_args(char **args, char *input);
char		**replace_env_var(char **temp);
char		**clean_quotes(char **temp);
int			has_quotes_before_spaces(char *str);
void		unclose_quotes_error(void);
int			skip_spaces(int i, int j, char *input);
static void	update_save(char **save, t_list *char_list);
char		*join_list(t_list *char_list);


// UTILS
void		new_prompt(int signal);
void		quit_exec(int signal);
void		new_line(int signal);
int			is_all_dollar(char *str);
int			is_all_blank(char *str);
int			is_all_valid_history(char *str);

//EXTRA
int			ft_chrpos(char *s, int c);
void		ft_free_matrix(char **matrix);

#endif
