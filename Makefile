NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

LINKER  =  -L./libft -lft -L./libft/ft_printf -lftprintf
INC = -I./libft -I./libft/get_next_line -I./libft/ft_printf
FSAN = -g3 -fsanitize=address

UTILS_DIR = ./push_swap_utils/
FILES = ft_swap.c \
		ft_push.c \
		ft_rotate.c \
		ft_reverse_rotate.c \
		ft_init_stacks.c \
		ft_sort.c \
		ft_check_args.c \
		main.c

UTILS = $(addprefix $(UTILS_DIR),$(FILES))
UTILS_OBJS = $(UTILS:.c=.o)


$(NAME): $(UTILS_OBJS)
	@make -C ./libft
	cc $(CFLAGS) $(FSAN) $(LINKER) ./libft/libft.a $(UTILS) -o $(NAME)

all: $(NAME)

clean:
	@make clean -C ./libft
	$(RM) $(UTILS_OBJS)

fclean: clean
	@make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

bonus: 
