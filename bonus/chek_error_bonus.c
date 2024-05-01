/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:17:27 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 21:28:14 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	cheek(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	delete_double(t_list *stak_a)
{
	t_list	*help;

	while (stak_a)
	{
		help = stak_a->next;
		while (help)
		{
			if (*(int *)(stak_a->content) == *(int *)(help->content))
				return (1);
			help = help->next;
		}
		stak_a = stak_a->next;
	}
	return (0);
}

void	error(t_list **stak)
{
	free_stack(stak);
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
		free((*stack)->content);
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
	*stack = NULL;
}

void	exit_error(t_list **stack_a, t_list **stack_b, char *str)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	free(str);
	write(2, "Error\n", 6);
	exit (1);
}
