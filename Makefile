NAME = minishell
FLAGS = -Wall -Werror -Wextra
READLIBH = -I /Users/jonascim/.brew/Cellar/readline/8.2.1/include
READLIB = -lreadline -L /Users/jonascim/.brew/Cellar/readline/8.2.1/lib
LIBFT = libft.a
LSRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbr_of_digits.c \
ft_power_of.c get_next_line.c ft_isspace.c ft_abs.c ft_min.c ft_max.c ft_strrev.c ft_isprime.c ft_strdel.c ft_memdel.c
LOBJECTS = $(LSRCS:.c=.o)
LODEST = $(addprefix ./libft/, $(LOBJECTS))
SYSTEM = exec_cmd.c init_data.c prompt.c
SYSTEMDEST = $(addprefix ./system/, $(SYSTEM))
BUILTINS = cd_prompt.c echo_prompt.c env_prompt.c exit_prompt.c export_prompt.c pwd_prompt.c exec_builtin.c
BUILTINSDEST = $(addprefix ./builtins/, $(BUILTINS))
PIPE = pipe_args.c pipe_checker.c
PIPEDEST = $(addprefix ./pipe/, $(PIPE))
REDIRECT = here_doc.c redirect_args.c redirect_input_cleaning.c redirect.c
REDIRECTDEST = $(addprefix ./redirect/, $(REDIRECT))
TOKENIZER = clean_quotes.c replace_env_var.c split_args.c tokenizer_utils.c tokenizer.c
TOKENIZERDEST = $(addprefix ./tokenizer/, $(TOKENIZER))
UTILS = export_utils.c fd_utils.c is_all.c is_builtin.c libft_extra_utils.c pipe_utils.c signals.c
UTILSDEST = $(addprefix ./utils/, $(UTILS))
SRCS = main.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS) $(SYSTEMDEST) $(BUILTINSDEST) $(PIPEDEST) $(REDIRECTDEST) $(TOKENIZERDEST) $(UTILSDEST))
SANITIZER = -fsanitize=address
all: $(NAME)

$(NAME): $(SRCSDEST) main.c
	@make -C libft
	@make bonus -C libft
	cc $(FLAGS) -o $(NAME) main.c $(SRCSDEST) -L. ./libft/$(LIBFT) $(READLIB) $(READLIBH)

clean:
	rm -f $(LODEST) ./libft/*.o ./libft/ft_printf/*.o

fclean:
	rm -f $(NAME) ./libft/$(LIBFT)

re: fclean all

$(LIBFT):
	make -C libft
