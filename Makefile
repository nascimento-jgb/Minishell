NAME = minishell
CC = gcc
CFLAGS = -Werror -Wall -Wextra
COMFILE_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
OBJ_FLAGS = -I${HOME}/.brew/opt/readline/include
MAIN_SRCS =  $(addprefix srcs/, mini_main.c)
BUILTIN_SRCS = $(addprefix srcs/builtins/, cd_prompt.c echo_prompt.c env_prompt.c exit_prompt.c export_prompt.c pwd_prompt.c unset_prompt.c exec_builtin.c)
PIPE_SRCS = $(addprefix srcs/pipe/, pipe_args.c pipe_checker.c)
REDIRECT_SRCS = $(addprefix srcs/redirect/, here_doc.c redirect_args.c redirect_input_cleaning.c redirect.c)
SYSTEM_SRCS = $(addprefix srcs/system/, exec_cmd.c init_data.c prompt.c)
TOKENIZER_SRCS = $(addprefix srcs/tokenizer/, clean_quotes.c replace_env_var.c split_args.c tokenizer_utils.c tokenizer.c)
UTILS_SRCS = $(addprefix srcs/utils/, export_utils.c fd_utils.c is_all.c is_builtin.c libft_extra_utils.c pipe_utils.c signals.c)
LIBFT_SRCS = $(addprefix srcs/libft/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_power_of.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c ft_isspace.c \
ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c ft_strdel.c ft_memdel.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lst_print.c)

MAIN_OBJS = $(MAIN_SRCS:.c=.o)
BUILTIN_OBJS = $(BUILTIN_SRCS:.c=.o)
PIPE_OBJS = $(PIPE_SRCS:.c=.o)
REDIRECT_OBJS = $(REDIRECT_SRCS:.c=.o)
SYSTEM_OBJS = $(SYSTEM_SRCS:.c=.o)
TOKENIZER_OBJS = $(TOKENIZER_SRCS:.c=.o)
UTILS_OBJS = $(UTILS_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MAIN_OBJS) $(LIBFT_OBJS) $(BUILTIN_OBJS) $(PIPE_OBJS) $(REDIRECT_OBJS) $(SYSTEM_OBJS) $(TOKENIZER_OBJS) $(UTILS_OBJS) $(LIBFTBONUS_OBJS)
	@$(CC) $(CFLAGS) $(COMFILE_FLAGS) $(MAIN_OBJS) $(LIBFT_OBJS) $(BUILTIN_OBJS) $(PIPE_OBJS) $(REDIRECT_OBJS) $(SYSTEM_OBJS) $(TOKENIZER_OBJS) $(UTILS_OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@

clean :
	@rm -rf $(MAIN_OBJS) $(LIBFT_OBJS) $(BUILTIN_OBJS) $(PIPE_OBJS) $(REDIRECT_OBJS) $(SYSTEM_OBJS) $(TOKENIZER_OBJS) $(UTILS_OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
