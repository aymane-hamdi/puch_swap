#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H
#include<stdio.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include<stdlib.h>
#include<unistd.h>

int cheek(char *str);
int delete_double(t_list *stak_a);
void del(void* content);
void sa(t_list **stak, char c);
void ss(t_list **stak_a,t_list **stak_b);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);
void	free_stack(t_list **stack);
void	exit_error(t_list **stack_a, t_list **stack_b);
void  cheeek_sort(t_list  **stak_a , t_list  **stak_b);
int chek_sort(t_list *stak_a);
#endif