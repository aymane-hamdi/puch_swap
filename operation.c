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
void ft_lstdel_last(t_list **lst, void (*del)(void*))
{
    t_list *last;
    t_list *prev;

    if(!(*lst) || !del) 
        return;

    last = ft_lstlast(*lst);

    // If the list has only one node
    if (*lst == last)
    {
        del(last->content);
        free(last);
        *lst = NULL;
    }
    else
    {
        prev = *lst;
        while(prev->next != last)
            prev = prev->next;
        prev->next = NULL;
        del(last->content);
        free(last);
    }
}
void push(t_list **from_stak, t_list **to_stak, char c)
{
    if (from_stak == NULL || to_stak == NULL)
    {
        write(1, "Error: Null pointer\n", 20);
        return;
    }
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
   t_list *last_node;

    if (*from_stak == NULL)
    {
        write(1, "Invalid input.\n", 15);
        return;
    }

    last_node = ft_lstlast(*from_stak);
    ft_lstadd_front(to_stak, last_node);
    ft_lstdel_last(from_stak,del);
}