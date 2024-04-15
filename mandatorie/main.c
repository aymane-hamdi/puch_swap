/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/04/15 13:29:10 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sort(t_list **stak_sort,t_list **stak2)
{
    if (chek_sort_inverse(*stak_sort) == 1 && ft_lstsize(*stak_sort) >= 5)
            reverse_list(stak_sort,stak2);
    else if(ft_lstsize(*stak_sort) <= 5)
        sort_simple(stak_sort,stak2);
    else
        sort_rang(stak_sort,stak2);
}

static void whil_loop(char **argv,int i,  t_list  **stak_a)
{
    t_list  *neoud = NULL;
    int *p;

    while(argv[++i])
    {
        if(cheek(argv[i]) == 1)
        { 
            p = malloc(sizeof(int));
            if(!p)
                exit(0);
            *p = ft_atoi(argv[i]);
            neoud = ft_lstnew(p);
            if (neoud == NULL)
            {
                free(p);
                write(1,"Error\n",6);
                exit(1);
            }
            ft_lstadd_back(stak_a, neoud); 
        }
        else
        error(stak_a);
    }
}

int main(int argc , char ** argv)
{
    int i;
    t_list  *stak_a = NULL; 
    t_list  *stak_b = NULL;
    
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
    whil_loop(argv,i,&stak_a);
    if (delete_double(stak_a) == 1 || chek_sort(stak_a) == 1)
    {
        write(1,"Error double\n",14);
        free_stack(&stak_a);
        exit(1);
    }
    sort(&stak_a,&stak_b);
    return(0);
}
