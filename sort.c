/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 22:45:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/31 18:14:56 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h" 

int	get_min(t_list **stack)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = (*(int *)head->content);
	while (head->next)
	{
		head = head->next;
		if (((*(int *)head->content) < min))
			min =(*(int *)head->content);
	}
	return (min);
}
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
    int min;

    min = get_min(stak_sort);
    while((*(int*)(*stak_sort)->content) != min)
    {
        ra(stak_sort);
    }
    pb(stak_sort,stak2);
    sort_tree_element(stak_sort);
    pa(stak_sort,stak2);
}
void sort_five_element(t_list **stak_sort,t_list **stak2)
{ 
    int min;

    min = get_min(stak_sort);
    while((*(int*)(*stak_sort)->content) != min)
    {
        ra(stak_sort);
    }
    pb(stak_sort,stak2);
   sort_four_element(stak_sort,stak2);
    pa(stak_sort,stak2);
}
void sort_simple(t_list **stak_sort,t_list **stak2)
{
    int len;

    len = ft_lstsize(*stak_sort);
    if(len == 3)
        sort_tree_element(stak_sort);
    if(len == 4)
        sort_four_element(stak_sort,stak2);
    if(len == 5)
        sort_five_element(stak_sort,stak2);
    else
        return;
}