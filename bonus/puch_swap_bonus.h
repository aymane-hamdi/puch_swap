#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include<stdlib.h>
#include<unistd.h>

int 	cheek(char *str);
void 	error(t_list  **stak_a);
int 	delete_double(t_list *stak_a);
void 	sa(t_list **stak, char c);
void 	ss(t_list **stak_a,t_list **stak_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	exit_error(t_list **stack_a, t_list **stack_b);
void	cheeek_sort(t_list  **stak_a , t_list  **stak_b);
int		chek_sort(t_list *stak_a);
#endif