NAME = push_swap
CC = cc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -rf

LINKER  =  -L./libft -lft -L./libft/ft_printf -lftprintf
INC = -I./libft -I./libft/get_next_line -I./libft/ft_printf
FSAN = -g3 -fsanitize=address

UTILS_DIR = ./push_swap_utils
UTILS = $(UTILS_DIR)/ft_swap.c \
		$(UTILS_DIR)/ft_push.c \
		$(UTILS_DIR)/ft_rotate.c \
		$(UTILS_DIR)/ft_reverse_rotate.c \
		$(UTILS_DIR)/ft_init_stacks.c \
		# $(UTILS_DIR)/ft_is_sorted.c \
		# $(UTILS_DIR)/ft_is_sorted_rev.c \
		# $(UTILS_DIR)/ft_get_min.c \
		# $(UTILS_DIR)/ft_get_max.c \
		# $(UTILS_DIR)/ft_get_min_index.c \
		# $(UTILS_DIR)/ft_get_max_index.c \
		# $(UTILS_DIR)/ft_get_median.c \
		# $(UTILS_DIR)/ft_get_median_index.c 
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
