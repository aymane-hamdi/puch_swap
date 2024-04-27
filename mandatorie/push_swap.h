/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/27 19:08:00 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// #include<stdio.h>
#include<stdlib.h>
#include "../libft/libft.h"

void	exit_error(t_list **stack_a, t_list **stack_b);
void del(void* content);
void error(t_list  **stak_a);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);
void sa( t_list **stak, char c);
void ss(t_list **stak_a,t_list **stak_b);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);
int cheek(char *str);
int chek_sort(t_list *stak_a);
int delete_double(t_list *stak_a);
void sort_tree_element(t_list **stak);
void sort_five_element(t_list **stak_sort,t_list **stak2);
void sort_four_element(t_list **stak_sort,t_list **stak2);
void   sort_simple(t_list **stak_sort,t_list **stak2);
int	get_min(t_list **stack);
void index_list(t_list **stack);
void sort_list(t_list **stak_sort,t_list **stak2);
void sort_rang(t_list **stak_sort,t_list **stak2);
int	get_max(t_list **stack);
void	free_stack(t_list **stack);
void reverse_list(t_list **stack_a, t_list **stack_b);
int chek_sort_inverse(t_list *stak_a);
#endif