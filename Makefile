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
PROMPT = open_shell.c get_directory.c prompt.c
PROMPTDEST = $(addprefix ./prompt/, $(PROMPT))
BUILTINS = cd.c pwd.c echo.c env.c export.c unset.c exit.c
BUILTINSDEST = $(addprefix ./builtins/, $(BUILTINS))
VARS = vars_new.c vars_addback.c vars_delnode.c vars_list_clear.c vars_removenode.c vars_length.c
VARSDEST = $(addprefix ./vars/, $(VARS))
SIGNALS = signals.c
SIGNALSDEST = $(addprefix ./signals/, $(SIGNALS))
PARSER = parsing_utils.c parsing.c initializing.c get_n_run.c get_n_run_utils.c check_builtins.c
PARSERDEST = $(addprefix ./parser/, $(PARSER))
SRCS = handle_errors.c clean.c get_env.c minishell_init.c utils.c
SRCSDEST = $(addprefix ./srcs/, $(SRCS) $(PROMPTDEST) $(BUILTINSDEST) $(VARSDEST) $(SIGNALSDEST) $(PARSERDEST))
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
