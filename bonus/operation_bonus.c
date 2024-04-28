 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:53:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/30 23:14:14 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "puch_swap_bonus.h"

void sa(t_list **stak, char c)
{
    t_list *tmp;

    if (ft_lstsize(*stak) < 2)
		error(stak);
    tmp = (*stak)->next;
    (*stak)->next = tmp->next;
    tmp->next = *stak;
    *stak = tmp;

    if(c == 'a')
        write(1,"sa\n",3);
    if(c == 'b')
        write(1,"sb\n",3);
}

void ss(t_list **stak_a,t_list **stak_b)
{
	if ((ft_lstsize(*stak_a) < 2) || (ft_lstsize(*stak_b) < 2))
		exit_error(stak_a, stak_b);
    sa(stak_a,'a');
    sa(stak_b,'b');
	write(1,"ss\n",3);
}

int push(t_list **stack_to, t_list **stack_from)
{
	t_list *tmp;
    if (ft_lstsize(*stack_from) == 0)
        return (-1);
    tmp = *stack_from;
    *stack_from = (*stack_from)->next;
    tmp->next = *stack_to;
    *stack_to = tmp;
    return 0;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		exit_error(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		exit_error(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}

void	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		error(stack_a);;
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		error(stack_b);;
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		exit_error(stack_a, stack_b);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}

int	reverseRotate(t_list **stack)
{
	t_list	*head;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

void	rra(t_list **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		error(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		error(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		exit_error(stack_a, stack_b);;
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
}