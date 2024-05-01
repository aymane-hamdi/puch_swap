/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:48:48 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 18:53:51 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **stak_sort, t_list **stak2)
{
	if (chek_sort_inverse(*stak_sort) == 1 && ft_lstsize(*stak_sort) >= 5)
		reverse_list(stak_sort, stak2);
	else if (ft_lstsize(*stak_sort) <= 5)
		sort_simple(stak_sort, stak2);
	else
		sort_rang(stak_sort, stak2);
	free_stack(stak_sort);
	free_stack(stak2);
}

int	chek_sort(t_list *stak_a)
{
	t_list	*help;
	int		count;

	count = 1;
	help = stak_a;
	while (help->next)
	{
		if (*(int *)help->content < *(int *)help->next->content)
			count++;
		help = help->next;
	}
	if (ft_lstsize(stak_a) == count)
		return (1);
	else
		return (0);
}

int	chek_sort_inverse(t_list *stak_a)
{
	t_list	*help;
	int		count;

	count = 1;
	help = stak_a;
	while (help->next)
	{
		if (*(int *)help->content > *(int *)help->next->content)
			count++;
		help = help->next;
	}
	if (ft_lstsize(stak_a) == count)
		return (1);
	else
		return (0);
}
