/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:03:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/02 16:41:20 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_list **stak)
{
	t_list	*tmp;

	if (ft_lstsize(*stak) < 2)
		return ;
	tmp = (*stak)->next;
	(*stak)->next = tmp->next;
	tmp->next = *stak;
	*stak = tmp;
}

void	ss(t_list **stak_a, t_list **stak_b)
{
	if ((ft_lstsize(*stak_a) < 2) || (ft_lstsize(*stak_b) < 2))
		return ;
	swap(stak_a);
	swap(stak_b);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = *stack_to;
	*stack_to = tmp;
	return (0);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return ;
}
