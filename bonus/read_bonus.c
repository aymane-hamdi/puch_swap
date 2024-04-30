/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:04:40 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/30 11:18:42 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static char	*checker(void)
{
	char	*line;
	char	*str;
	char	*temp;

	line = get_next_line(0);
	while (line)
	{
		temp = str;
		str = ft_strjoin(str, line);
		free(temp);
		line = get_next_line(0);
	}
	free(line);
	return (str);
}

static void	loop(char *split, t_list **stak_a, t_list **stak_b)
{
	if (ft_strncmp(split, "sa", ft_strlen(split)) == 0)
		sa(stak_a, 'a');
	if (ft_strncmp(split, "sb", ft_strlen(split)) == 0)
		sa(stak_b, 'b');
	if (ft_strncmp(split, "ss", ft_strlen(split)) == 0)
		ss(stak_a, stak_b);
	if (ft_strncmp(split, "pa", ft_strlen(split)) == 0)
		pa(stak_a, stak_b);
	if (ft_strncmp(split, "pb", ft_strlen(split)) == 0)
		pb(stak_a, stak_b);
	if (ft_strncmp(split, "ra", ft_strlen(split)) == 0)
		ra(stak_a);
	if (ft_strncmp(split, "rb", ft_strlen(split)) == 0)
		rb(stak_b);
	if (ft_strncmp(split, "rr", ft_strlen(split)) == 0)
		rr(stak_a, stak_b);
	if (ft_strncmp(split, "rra", ft_strlen(split)) == 0)
		rra(stak_a);
	if (ft_strncmp(split, "rrb", ft_strlen(split)) == 0)
		rrb(stak_b);
	if (ft_strncmp(split, "rrr", ft_strlen(split)) == 0)
		rrr(stak_a, stak_b);
}

void	cheeek_sort(t_list **stak_a, t_list **stak_b)
{
	char	**split;

	split = ft_split(checker(), '\n');
	if (split != NULL)
	{
		while (*split)
		{
			loop(*split, stak_a, stak_b);
			split++;
		}
	}
	if (chek_sort(*stak_a) == 1 && ft_lstsize(*stak_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
