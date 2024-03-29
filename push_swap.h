/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:35 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/28 20:14:55 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "libft/libft.h"


void del(void* content);
void sa(int **stak, int len, char c);
void ss(int **stak_a, int **stak_b, int len_a, int len_b);
int cheek(char *str);
int delete_double(t_list *stak_a);
#endif