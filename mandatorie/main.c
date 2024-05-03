/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/03 16:45:11 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_list	*stak_a;
	t_list	*stak_b;

	stak_a = NULL;
	stak_b = NULL;
	atexit(chek_leaks);
	handl_erro(argv, argc);
	whil_loop(argv, argc, &stak_a);
	if (delete_double(stak_a) == 1)
		error(&stak_a);
	if (chek_sort(stak_a) == 1)
	{
		free_stack(&stak_a);
		exit(0);
	}
	sort(&stak_a, &stak_b);
	return (0);
}
