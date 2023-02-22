/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:39:36 by jonascim          #+#    #+#             */
/*   Updated: 2023/02/22 16:50:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES
# include "../srcs/libft/libft.h"
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

// FUNCTIONS -
// SYSTEM
void		run_prompt(char **envp);
char		**envp_dup(char **envp);
void		init_gvar_data(void);
void		initial_message(void);
void		execute_general(char **input);
void		exec_cmd(char **args);

// TOKENIZER
char		**tokenizer(char *input);
int			increment_quotes(int i, char *input);
int			increment_count(int i, int c, char *input);
void		split_args(char **args, char *input);
char		**replace_env_var(char **temp);
char		**clean_quotes(char **temp);
int			quotes_before_space(char *str);
void		unclosed_quotes_error_msg(void);
int			skip_spaces(int i, int j, char *input);
char		*join_list(t_list *char_list);

//PIPE
void		pipe_checker(void);
char		**pipe_args(void);
int			increment_all_str_quotes(char *str, int i);

//REDIRECT
void		redirect(char **input);
char		**redirect_args(char **temp);
void		here_doc(char *eof);
void		redirect_input_cleaning(char **args, char **input);

//BUILTINS
void		exec_builtin(char **args, int code);
void		cd_prompt(char **args);
void		export_prompt(char **args);
void		exit_prompt(void);
void		pwd_prompt(void);
void		env_prompt(void);
void		unset_prompt(char **args);
void		echo_prompt(char **args);
void		check_eof(char *input);

// UTILS
void		pipe_stop(int signal);
void		here_doc_stop(int signal);
void		continue_add_pipe_arg(t_list **lst);
void		new_prompt(int signal);
void		quit_exec(int signal);
void		new_line(int signal);
int			is_all_dollar(char *str);
int			is_all_blank(char *str);
int			is_all_digit(char *c, int len);
int			is_all_valid_history(char *str);
int			is_valid_attribution(char *arg, char *next);
int			is_builtin(char **args);
int			is_exit_cmd(void);
void		change_fd(int *fd);
void		save_fd(int *fd);
void		change_output(char *file, int flags);
void		change_input(char *file, int flags);

//EXTRA
int			ft_chrpos(char *s, int c);
void		ft_free_ptr(void **ptr);
void		ft_free_matrix(char **matrix);
char		*ft_matrix_to_str(char **matrix);
char		**ft_lst_to_matrix(t_list *lst);
int			ft_chrqty(char *s, int c);

#endif
