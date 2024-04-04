src = operation.c sort.c radix.c main.c chek_error.c

obj = $(src:.c=.o)

NAME =	push_swap
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(obj)
	$(MAKE) -C libft bonus
	gcc -o $(NAME) $(obj) $(LIBFT)

%.o: %.c
	gcc -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(obj)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re