/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/31 21:25:26 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "libft/libft.h"
#include<string.h>
void del(void* content);
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
void quickSort(t_list **stack_a, t_list **stack_b);
int	get_min(t_list **stack);
#endif