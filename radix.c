/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:00:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/31 22:31:30 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list **stack)
{
	t_list	*head;
	int		max;

	head = *stack;
	max = (*(int *)head->content);
	while (head->next)
	{
		head = head->next;
		if (((*(int *)head->content) > max))
			max =(*(int *)head->content);
	}
	return (max);
}
void sort_big(t_list **stak_sort,t_list **stak2)
{
    t_list *help;
    t_list *help2;
    int max;

   help = *stak_sort;
while(help)
{
    pb(stak_sort,stak2);
    help = help->next;
}
help = *stak2;
while(help) // changed from while(stak2) to while(help)
{
    max = get_max(stak2);
    help2 = *stak2;
    while((*(int*)help2->content) != max)
    {
        ra(stak2);
    }
    pa(stak_sort,stak2);
    help = help->next; // you also need to move to the next element in the stack
}
}