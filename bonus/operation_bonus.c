/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:53:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 18:11:38 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}

void	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return ;
}

void	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	rotate(stack_a);
	rotate(stack_b);
}

int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}
