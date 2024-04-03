src = operation.c sort.c radix.c main.c chek_error.c  

obj = $(src:.c=.o)

NAME =	push_swap
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(obj)
	@make -C libft
	@gcc -Wall -Wextra -Werror -o $(NAME) $(obj)  $(LIBFT)

%.o: %.c push_swap.h
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(obj)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re