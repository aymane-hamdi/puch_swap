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
void partition(t_list **stack_a, t_list **stack_b)
{
    int pivot = (*(int *)(*stack_a)->content);
    t_list *current = (*stack_a);

    while (current)
    {
        if ((*(int *)(current->content)) > pivot)
        {
            pb(stack_a, stack_b);
            current = (*stack_a);
        }
        else
        {
            current = current->next;
        }
    }
}

void quickSort(t_list **stack_a, t_list **stack_b)
{
    if (!(*stack_a) || !(*stack_a)->next)
        return;

    partition(stack_a, stack_b);

    quickSort(stack_a, stack_b);

    while (*stack_b)
    {
        pa(stack_a, stack_b);
    }

    quickSort(&((*stack_a)->next), stack_b);
}