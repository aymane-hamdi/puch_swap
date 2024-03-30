/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:55:39 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/29 23:56:31 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ptint_stak( t_list  *stak_a)
{
     t_list  *help;
    
    help = stak_a;
    if (stak_a == NULL){
        write(1, "Invalid input.\n", 15);
        return;
    }

    while(help)
    {
      printf("%d\n", *((int *)help->content));
        help = help->next;

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
    else
    {
        push(&stak_a, &stak_b, 'a');
        ptint_stak(stak_a);
        printf("**********\n");
        ptint_stak(stak_b);
    }
   
    return(0);
}
