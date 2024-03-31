/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:45:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/31 01:50:59 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h" 

void sort_tree_element(t_list **stak)
{
    t_list *help;
    int first;
    int second;
    int third;
    
    help = *stak;
    first =  (*(int*)help->content);
    second =(*(int*)help->next->content);
    third = (*(int*)help->next->next->content);
    if( first > second && second <  third && first < third)
        sa(stak,'a');
    else if(first > second && second >  third && first > third)
    {
        sa(stak,'a');
        rra(stak);
    }
    else if( first > second && second <  third && first > third)
        ra(stak);
    else if( first < second && second >  third && first > third)
       rra(stak);
    else if( first < second && second >  third && first < third)
    {
        sa(stak,'a');
        ra(stak);
    }
    else
        return;
}
void sort_four_element(t_list **stak_sort,t_list **stak2)
{
    t_list *help;
    int min;
    int pos = 0;
    help = *stak_sort;
    min = (*(int*)help->content);
    while(help)
    {
        if(min >= (*(int*)help->content))
        {
            min = (*(int*)help->content);
            pos++;
        }
        help = help->next;
    }
    if(pos == 1)
    {
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    else if(pos == 2) // Changed this condition from pos == 1 to pos == 2
    {
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    else if(pos == 3) // Changed this condition from pos == 2 to pos == 3
    {
        ra(stak_sort);
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    else
    {
        rra(stak_sort);
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
}
void sort_five_element(t_list **stak_sort,t_list **stak2)
{ 
   t_list *help;
    int min;
    int pos = 0;
    help = *stak_sort;
    min = (*(int*)help->content);
    while(help)
    {
        if(min >= (*(int*)help->content))
        {
            min = (*(int*)help->content);
            pos++;
        }
        help = help->next;
    }
    if(pos == 1)
    {
        pb(stak_sort,stak2);
       sort_four_element(stak_sort,stak2);
        pa(stak_sort,stak2);
    }
    else if(pos == 2) // Changed this condition from pos == 1 to pos == 2
    {
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_four_element(stak_sort,stak2);;
        pa(stak_sort,stak2);
    }
    else if(pos == 3) // Changed this condition from pos == 2 to pos == 3
    {
        ra(stak_sort);
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_four_element(stak_sort,stak2);;
        pa(stak_sort,stak2);
    }
    else
    {
        rra(stak_sort);
        pb(stak_sort,stak2);
        sort_four_element(stak_sort,stak2);;
        pa(stak_sort,stak2);
    }
    
}