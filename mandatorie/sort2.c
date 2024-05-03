/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:48:48 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 19:22:27 by ahamdi           ###   ########.fr       */
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

void	handl_erro(char **argv, int argc)
{
	if (argc == 1)
		exit(0);
	if (ft_count_words(argv[1], ' ') == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (ft_count_words(argv[1], ' ') == 1 && argc == 2)
	{
		if (cheek(argv[1]) == 0 || ft_atoi(argv[1]) > 2147483647 
			|| ft_atoi(argv[1]) < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		exit(0);
	}
}
