/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/02 16:19:02 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"

void	sort(t_list **stak_sort, t_list **stak2);
void	handl_erro(char **argv, int argc);
void	free_arry(char **str);
int		position(t_list *head, int num);
void	chack_null(char **argv, int *i);
int		ft_count_words(char const *str, char sep);
void	exit_error(t_list **stack_a, t_list **stack_b);
void	error(t_list **stak_a);
void	sa(t_list **stak, char c);
void	ss(t_list **stak_a, t_list **stak_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		cheek(char *str);
int		chek_sort(t_list *stak_a);
int		delete_double(t_list *stak_a);
void	sort_tree_element(t_list **stak);
void	sort_five_element(t_list **stak_sort, t_list **stak2);
void	sort_four_element(t_list **stak_sort, t_list **stak2);
void	sort_simple(t_list **stak_sort, t_list **stak2);
int		get_min(t_list **stack);
void	index_list(t_list **stack);
void	sort_list(t_list **stak_sort, t_list **stak2);
void	sort_rang(t_list **stak_sort, t_list **stak2);
int		get_max(t_list **stack);
void	free_stack(t_list **stack);
void	reverse_list(t_list **stack_a, t_list **stack_b);
int		chek_sort_inverse(t_list *stak_a);
#endif