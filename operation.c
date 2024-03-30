/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:53:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/30 01:27:04 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sa(t_list **stak, char c)
{
    t_list *tmp;

    if(*stak == NULL || (*stak)->next == NULL)
    {
        write(1,"Error\n",6);
        return;
    }

    tmp = (*stak)->next;
    (*stak)->next = tmp->next;
    tmp->next = *stak;
    *stak = tmp;

    if(c == 'a')
        write(1,"swap a\n",7);
    if(c == 'b')
        write(1,"swap b\n",7);
}
void ss(t_list **stak_a,t_list **stak_b)
{
    sa(stak_a,'a');
    sa(stak_b,'b');
}
// void met_data(int **stak_1, int **stak_2, int len_1, int len_2)
// {
    
// // }
void push(t_list **from_stak, t_list **to_stak, char c)
{
    t_list *last;
    t_list *prev;

    if(c == 'a' && *from_stak == NULL)
    {
        write(1,"Error\n",6);
        exit(1);
    }
    if(c == 'b' && *to_stak == NULL)
    {
        write(1,"Error\n",6);
        exit(1);
    }
    last = ft_lstlast(*from_stak);
    prev = *from_stak;
    while (prev->next != last)
    {
        prev = prev->next;
    }
    prev->next = NULL;

    ft_lstadd_front(to_stak, last);
    ft_lstdelone(last, del);
}
