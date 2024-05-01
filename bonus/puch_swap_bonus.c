/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puch_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:09:07 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 12:20:19 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i = -1;
	}
	whil_loop(argv, i, &stak_a);
	cheeek_sort(&stak_a, &stak_b);
	free_stack(&stak_a);
	free_stack(&stak_b);
}
