/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:04:40 by ahamdi            #+#    #+#             */
/*   Updated: 2024/05/01 21:18:23 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	chek_sort(t_list *stak_a)
{
	t_list	*help;
	int		count;

	if (ft_lstsize(stak_a) == 0)
		return (0);
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

static void	loop(char *str, t_list **stak_a, t_list **stak_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stak_a, 'a');
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sa(stak_b, 'b');
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stak_a, stak_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stak_a, stak_b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stak_a, stak_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stak_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stak_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stak_a, stak_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stak_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stak_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stak_a, stak_b);
	else
		exit_error(stak_a, stak_b);
}

void	cheeek_sort(t_list **stak_a, t_list **stak_b)
{
	char	*line;
	char	*str;
	char	*temp;

	line = get_next_line(0);
	while (line)
	{
		loop(line, stak_a, stak_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (chek_sort(*stak_a) == 1 && ft_lstsize(*stak_b) == 0)
	{
		free_stack(stak_a);
		free_stack(stak_b);
		write(1, "OK\n", 3);
	}
	else
	{
		free_stack(stak_a);
		free_stack(stak_b);
		write(1, "KO\n", 3);
	}
}
