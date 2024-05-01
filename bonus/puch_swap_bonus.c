/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puch_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:09:07 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 21:28:40 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	else_loop(int *p, t_list **stak_a, char *str, char **argv)
{
	if (ft_count_words(str, ' ') > 1)
		free_arry(argv);
	free(p);
	error(stak_a);
}

static void	whil_loop(char **argv, int i, t_list **stak_a, char *str)
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
			else_loop(p, stak_a, str, argv);
	}
	if (ft_count_words(str, ' ') > 1)
		free_arry(argv);
	if (delete_double(*stak_a) == 1)
		error(stak_a);
}

static void	chack_null(char **argv, int *i)
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

static void	handl_erro(char **argv, int argc)
{
	if (argc == 1 || (ft_count_words(argv[1], ' ') == 1 && argc == 2))
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stak_a;
	t_list	*stak_b;
	char	*str;

	stak_a = NULL;
	stak_b = NULL;
	i = 0;
	str = argv[1];
	handl_erro(argv, argc);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		chack_null(argv, &i);
	}
	whil_loop(argv, i, &stak_a, str);
	cheeek_sort(&stak_a, &stak_b);
	free_stack(&stak_a);
	free_stack(&stak_b);
}
