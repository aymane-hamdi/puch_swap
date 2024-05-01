/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:54:05 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 16:12:19 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	chack_null(char **argv, int *i)
{
	if (!argv)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	else if (!argv[0])
	{
		free(argv);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	*i = -1;
}
