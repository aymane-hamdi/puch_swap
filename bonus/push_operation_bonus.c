/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:03:45 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/30 11:13:09 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_list **stak, char c)
{
	t_list	*tmp;

	if (ft_lstsize(*stak) < 2)
		error(stak);
	tmp = (*stak)->next;
	(*stak)->next = tmp->next;
	tmp->next = *stak;
	*stak = tmp;
}

void	ss(t_list **stak_a, t_list **stak_b)
{
	if ((ft_lstsize(*stak_a) < 2) || (ft_lstsize(*stak_b) < 2))
		exit_error(stak_a, stak_b);
	sa(stak_a, 'a');
	sa(stak_b, 'b');
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
		exit_error(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		exit_error(stack_a, stack_b);
}
