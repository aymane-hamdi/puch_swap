/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/03 23:01:17 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ptint_stak( t_list  *stak_a)
{
     t_list  *help;
    if(ft_lstsize(stak_a) == 0)
    {
        write(1, "Empty stack.\n", 13);
        return;
    }
    if (stak_a->content == NULL)
    {
        write(1, "Invalid input.\n", 15);
        return;
    }
    help = stak_a;
    while(help)
    {
      if (help->content)  // check that help->content is not NULL
      {
          printf("%d\n", *((int *)help->content));
      }
      help = help->next;
    }
}
void sort(t_list **stak_sort,t_list **stak2)
{
    if (chek_sort_inverse(*stak_sort) == 1 && ft_lstsize(*stak_sort) >= 5)
            reverse_list(stak_sort,stak2);
    else if(ft_lstsize(*stak_sort) <= 5)
        sort_simple(stak_sort,stak2);
    else
        sort_rang(stak_sort,stak2);
}

int main(int argc , char ** argv)
{
    int i;
    int *p;
    t_list  *stak_a = NULL; 
    t_list  *stak_b = NULL;
    t_list  *neoud = NULL;
    
    i = 0;
    if(argc == 2)
    {
        argv = ft_split(argv[1],' ');
        if(!argv)
        {
            write(1,"Error\n",6);
            exit(1);
        }
        i = -1;
    }
    while(argv[++i])
    {
        if(cheek(argv[i]) == 1)
        { 
            p = malloc(sizeof(int));
            *p = ft_atoi(argv[i]);
            neoud = ft_lstnew(p);
            if (neoud == NULL)
            {
                free(p);
                write(1,"Error\n",6);
                exit(1);
            }
            ft_lstadd_back(&stak_a, neoud); 
        }
        else
        {
            ft_lstclear(&stak_a, del);
            write(1,"Error\n",6);
            exit(1);
        }
    }
    if (!delete_double(stak_a) || !chek_sort(stak_a))
    {
        write(1,"Error double\n",14);
        ft_lstclear(&stak_a, del);
        exit(1);;
    }
    sort(&stak_a,&stak_b);
    return(0);
}