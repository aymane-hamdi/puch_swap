/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/29 23:47:23 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "libft/libft.h"


void del(void* content);
void sa( t_list **stak, char c);
void ss(t_list **stak_a,t_list **stak_b);
void push(t_list **stak_a, t_list **stak_b, char c);
int cheek(char *str);
int delete_double(t_list *stak_a);
#endif