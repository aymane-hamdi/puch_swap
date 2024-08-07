src = mandatorie/operation.c mandatorie/sort.c mandatorie/range.c mandatorie/main.c mandatorie/chek_error.c mandatorie/error.c mandatorie/push_operation.c mandatorie/revers_rotat.c mandatorie/sort2.c
srcb =  bonus/chek_error_bonus.c bonus/operation_bonus.c bonus/main_bonus.c bonus/read_bonus.c get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c bonus/revers_rotat_bonus.c  bonus/push_operation_bonus.c

obj = $(src:.c=.o)
objb = $(srcb:.c=.o)
NAME =	push_swap
bonus = checker
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

$(NAME): $(obj)
	make bonus -C libft 
	${CC} ${CFLAGS} -o $(NAME) $(obj) $(LIBFT)

bonus: $(objb)
	make bonus -C libft
	${CC} ${CFLAGS} -o $(bonus) $(objb) $(LIBFT)

%.o: %.c mandatorie/push_swap.h  bonus/puch_swap_bonus.h get_next_line/get_next_line.h
	${CC} ${CFLAGS} -c $< -o$@

clean:
	$(MAKE) -C libft clean
	rm -f $(obj) $(objb)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: clean