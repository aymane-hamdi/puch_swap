/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:00:31 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/30 10:25:12 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position(t_list *head, int num)
{
	t_list	*current;
	int		pos;

	pos = 0;
	current = head;
	while (current != NULL)
	{
		if (*((int *) current->content) == num)
		{
			return (pos);
		}
		current = current->next;
		pos++;
	}
	exit(1);
}

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
			max = (*(int *)head->content);
	}
	return (max);
}

void	index_list(t_list **stack)
{
	t_list	*current;
	t_list	*compare;
	int		index;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	index = 0;
	while (current)
	{
		compare = *stack;
		while (compare)
		{
			if (*((int *)current->content) > *((int *)compare->content))
				index++;
			compare = compare->next;
		}
		current->index = index;
		index = 0;
		current = current->next;
	}
}

static void	loop(t_list **stak_sort, t_list **stak2, int min, int max)
{
	t_list	*help;

	help = NULL;
	help = *stak_sort;
	while (help)
	{
		help = *stak_sort;
		if (help->index >= min && help->index <= max)
		{
			pb(stak_sort, stak2);
			help = *stak_sort;
			min++;
			max++;
		}
		else if (help->index < min)
		{
			pb(stak_sort, stak2);
			rb(stak2);
			max++;
			min++;
			help = *stak_sort;
		}
		else
			ra(stak_sort);
	}
}

void	sort_list(t_list **stak_sort, t_list **stak2)
{
	int		min;
	int		max;

	if (ft_lstsize(*stak_sort) <= 100)
		max = 15;
	else
		max = 32;
	min = 0;
	index_list(stak_sort);
	loop(stak_sort, stak2, min, max);
}
