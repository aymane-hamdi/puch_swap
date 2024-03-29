/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamdi <ahamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:53:36 by ahamdi            #+#    #+#             */
/*   Updated: 2024/03/28 18:24:31 by ahamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sa(int **stak, int len, char c)
{
    int tmp;

    if(len < 2 || !(*stak)[0] || !(*stak)[1])
    {
        write(1,"Error\n",6);
	    return ;
    }
    tmp = (*stak)[0];
   (*stak)[0] =(*stak)[1];
   (*stak)[1] = tmp;
   if(c == 'a')
     write(1,"swap a\n",7);
    if(c == 'b')
     write(1,"swap b\n",7);
}
void ss(int **stak_a, int **stak_b, int len_a, int len_b)
{
    sa(stak_a, len_a,'a');
      sa(stak_b, len_b,'b');
}
void met_data(int **stak_1, int **stak_2, int len_1, int len_2)
{
    
}
void ss(int **stak_a, int **stak_b, int len_a, int len_b , char c)
{
    if(c == 'b' ,len_a == 0)
    {
        write(1,"Error\n",6);
        exit(1);
    }
    if(c == 'a' ,len_b == 0)
    {
        write(1,"Error\n",6);
        exit(1);
    }
    
    if(c == 'a')
    {
        
    }
}
