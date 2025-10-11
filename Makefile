NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT=./libft/libft.a

SOURCE =	av_sort.c				\
			ft_stack_initializer.c	\
			ft_push_swap_utils.c

OBJECTS = 	av_sort.o				\
			ft_stack_initializer.o	\
			ft_push_swap_utils.o

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@cc $(CFLAGS) $(OBJECTS) $(LIBFT) push_swap.c -o $(NAME)

$(LIBFT):
	make -C ./libft
clean:
	@rm -rf $(OBJECTS)

fclean: $(OBJECTS)
	@rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus re_run

re_run:
	@cc $(CFLAGS) $(OBJECTS) push_swap.c -o $(NAME)
test_run: $(NAME)
	@./$(NAME) "50 20 10 40"
