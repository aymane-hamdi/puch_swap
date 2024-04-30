/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:56:24 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/28 12:58:53 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_list **stak_a)
{
	free_stack(stak_a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

void	reverse_list(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (i != size -1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i != size -1)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

void	sort_rang(t_list **stack_sort, t_list **stack2)
{
	int	max;
	int	size;

	sort_list(stack_sort, stack2);
	while (*stack2)
	{
		size = ft_lstsize(*stack2) / 2;
		max = get_max(stack2);
		if (*((int *)(*stack2)->content) == max)
			pa(stack_sort, stack2);
		else if (position(*stack2, max) <= size)
			rb(stack2);
		else
			rrb(stack2);
	}
}
