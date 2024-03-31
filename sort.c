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
    int first;
    int second;
    int third;
    int x;
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
    if(pos == 1)
    {
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    if(pos == 2)
    {
        ra(stak_sort);
        sa(stak_sort,'a');
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    if(pos == 3)
    {
        rra(stak_sort);
        pb(stak_sort,stak2);
        sort_tree_element(stak_sort);
        pa(stak_sort,stak2);
    }
    // pb(stak_sort,stak2);
    // sort_tree_element(stak_sort);
    // help = *stak_sort;
    // first =  (*(int*)help->content);
    // second =(*(int*)help->next->content);
    // third = (*(int*)help->next->next->content);
    // x = (*(int*)(*stak2)->content);
    // if(x < first)
    //     pa(stak_sort,stak2);
    // else if(x > first && x < second)
    // {
    //     pa(stak_sort,stak2);
    //     sa(stak_sort,'a');
    // }
    // else if(x > second && x < third)
    // {
    //     ra(stak_sort);
    //     pa(stak_sort,stak2);
    //     sa(stak_sort,'a');
    //     rra(stak_sort);
    // }
    // else
    // {
    //     ra(stak_sort);
    //     ra(stak_sort);
    //     pa(stak_sort,stak2);
    //     sa(stak_sort,'a');
    //     rra(stak_sort);
    //     rra(stak_sort);
    // }
    else 
        return ;
}
void sort_five_element(t_list **stak_sort,t_list **stak2)
{ 
    t_list *help;
    int oune;
    int too;
    int three;
    int foor ;
    int x;
    
    pb(stak_sort,stak2);
    sort_four_element(stak_sort,stak2);
    help = *stak_sort;
    oune =  (*(int*)help->content);
    too =(*(int*)help->next->content);
    three = (*(int*)help->next->next->content);
    foor = (*(int*)help->next->next->next->content);
    x = (*(int*)(*stak2)->content);
    if(x < oune)
        pa(stak_sort,stak2);
    else if(x > oune && x < too)
    {
        pa(stak_sort,stak2);
        sa(stak_sort,'a');
    }
    else if(x > too && x < three)
    {
        ra(stak_sort);
        pa(stak_sort,stak2);
        sa(stak_sort,'a');
        rra(stak_sort);
    }
    // else if(x > three && x < foor)
    // else
    // {
    //     ra(stak_sort);
    //     pa(stak_sort,stak2);
    //     sa(stak_sort,'a');
    //     rra(stak_sort);
    // }
    else 
        return ;
    
}