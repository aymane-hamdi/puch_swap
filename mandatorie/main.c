/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 12:22:17 by ahamdi           ###   ########.fr       */
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

static void	whil_loop(char **argv, int i, t_list **stak_a)
{
	t_list	*neoud;
	int		*p;

	neoud = NULL;
	while (argv[++i])
	{
		p = malloc(sizeof(int *));
		if (!p)
			exit(1);
		if (cheek(argv[i]) == 1)
		{
			*p = ft_atoi(argv[i]);
			neoud = ft_lstnew(p);
			if (neoud == NULL)
				error(stak_a);
			ft_lstadd_back(stak_a, neoud); 
		}
		else
			error(stak_a);
	}
	if (delete_double(*stak_a) == 1)
		error(stak_a);
}

static void	eror_arg(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stak_a;
	t_list	*stak_b;

	stak_a = NULL;
	stak_b = NULL;
	i = 0;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv || argv[0] == NULL)
			eror_arg();
		i = -1;
	}
	whil_loop(argv, i, &stak_a);
	if (chek_sort(stak_a) == 1)
	{
		free_stack(&stak_a);
		exit(0);
	}
	sort(&stak_a, &stak_b);
	return (0);
}
