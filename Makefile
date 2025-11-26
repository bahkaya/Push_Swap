# NAME = push_swap

# CFLAGS = -Wall -Wextra -Werror

# LIBFT=./libft/libft.a

# SOURCE =	av_sort.c				\
# 			ft_stack_initializer.c	\
# 			ft_push_swap_utils.c

# OBJECTS = 	av_sort.o				\
# 			ft_stack_initializer.o	\
# 			ft_push_swap_utils.o

# all: $(NAME)

# $(NAME): $(OBJECTS) $(LIBFT)
# 	@cc $(CFLAGS) $(OBJECTS) $(LIBFT) push_swap.c -o $(NAME)

# $(LIBFT):
# 	make -C ./libft
# clean:
# 	@rm -rf $(OBJECTS)

# fclean: $(OBJECTS)
# 	@rm -rf $(OBJECTS) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re bonus re_run

# re_run:
# 	@cc $(CFLAGS) $(OBJECTS) push_swap.c -o $(NAME)
# test_run: $(NAME)
# 	@./$(NAME) "50 20 10 40"


NAME := push_swap
CC := gcc
CFLAGS := -Wall -Wextra -Werror
LIBFT=./libft/libft.a

SRCS := \
	push_swap.c \
	av_sort.c \
	ft_stack_initializer.c \
	ft_push_swap_utils.c	\
	radix_sort_utils.c		\
	n_argv_sort.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -g

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	@$(CC) $(CFLAGS) $(OBJS) test.c

.PHONY: all clean fclean re
