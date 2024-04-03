/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:00:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/03 00:58:42 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *remove_node(t_list *head, t_list *node_to_remove)
{
    if (head == node_to_remove)
    {
        t_list *new_head = head->next;
        free(head);
        return new_head;
    }

    t_list *current = head;
    while (current && current->next != node_to_remove)
    {
        current = current->next;
    }

    if (current)
    {
        t_list *node_to_remove = current->next;
        current->next = node_to_remove->next;
        free(node_to_remove);
    }

    return head;
}
void index_list(t_list **stack)
{
    if (!stack || !*stack) return;  // check that stack and *stack are not NULL

    t_list  *help;
    t_list  *help2;
    int min;
    int indx;
    help2 = *stack;
    indx = 0;
    while (help2)
    {
        t_list *tmp2 = help2;
        min = get_min(&tmp2);
        printf("min = %d\n", min);
        help = NULL;
        for (t_list *tmp = help2; tmp; tmp = tmp->next)
        {
            if (tmp->content && (*(int*)tmp->content) == min)  // check that tmp->content is not NULL
            {
                help = tmp;
                break;
            }
        }

        if (help)
        {
            help->index = indx;
            indx++;
            help2 = remove_node(help2, help);
        }
    }
}