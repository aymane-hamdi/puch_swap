/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:09:07 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/02 16:37:15 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	else_loop(t_list **stak_a, char **str)
{
	free_arry(str);
	error(stak_a);
}

static void	while_loop_split(char **str, t_list **stak_a, t_list *neoud)
{
	int	j;
	int	*p;

	j = 0;
	while (str[j])
	{
		if (cheek(str[j]) == 1)
		{
			p = malloc(sizeof(int *));
			if (p == NULL)
				error(stak_a);
			*p = ft_atoi(str[j]);
			neoud = ft_lstnew(p);
			if (neoud == NULL)
				error(stak_a);
			ft_lstadd_back(stak_a, neoud); 
		}
		else
			else_loop(stak_a, str);
		j++;
	}
}

static void	whil_loop(char **argv, int argc, t_list **stak_a)
{
	t_list	*neoud;
	int		i;
	char	**str;

	neoud = NULL;
	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL)
			exit(1);
		while_loop_split(str, stak_a, neoud);
		free_arry(str);
		i++;
	}
}

static void	handl_erro(char **argv, int argc)
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

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stak_a;
	t_list	*stak_b;

	stak_a = NULL;
	stak_b = NULL;
	i = 0;
	handl_erro(argv, argc);
	whil_loop(argv, argc, &stak_a);
	if (delete_double(stak_a) == 1)
		error(&stak_a);
	cheeek_sort(&stak_a, &stak_b);
	free_stack(&stak_a);
	free_stack(&stak_b);
}
