/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/28 23:05:21 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ptint_stak(int *stak_a, int len)
{
    int i;
    
    if (stak_a == NULL || len <= 0) {
        write(1, "Invalid input.\n", 15);
        return;
    }
    i = 0;
    while(i < len)
    {
        printf("**%d**\n",stak_a[i]);
        i++;
    }
}


int main(int argc , char ** argv)
{
    int i;
    int *p;
    t_list  *stak_a = NULL; 
    t_list  *stak_b = NULL;
     t_list  *neoud =NULL;
    
    i = 0;
    if(argc == 2)
    {
        argv = ft_split(argv[1],' ');
        i = -1;
    }
    if(!argv)
    {
        write(1,"Error\n",6);
        exit(1);
    }
    i++;
    while(argv[i++])
    {
        if(cheek(argv[i]) == 1)
        { 
         int *p = malloc(sizeof(int));
            if (p == NULL) // Check if malloc succeeded
            {
                write(1,"Error\n",6);
                exit(1);
            }
            *p = ft_atoi(argv[i]);
            t_list *neoud = ft_lstnew(p);
            if (neoud == NULL) // Check if ft_lstnew succeeded
            {
                free(p); // Free p to avoid memory leak
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
    
   if(delete_double(stak_a ) == 0)
    {
        ft_lstclear(&stak_a, del);
        write(1,"Error\n",6);
        exit(1);
    }
    i++;
}
