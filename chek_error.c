#include"push_swap.h"

int cheek(char *str)
{
    int i;

    if(!str[0])
        return(0);
    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    if(!str[i])
        return(0);
    while(str[i])
    {
        if(ft_isdigit(str[i]) == 0)
            return(0);
        i++;
    }
    return(1);
}

int delete_double( t_list *stak_a)
{
   t_list *help;
    t_list *help2;

    help = stak_a;
    help2 =help->next;
    while(help)
    {
        while(help2)
        {
            if (help->content == help ->next->content)
                return(0);
            help2 = help2->next;
        }
        help = help->next;
    }
    return(1);
}
void del(void* content)
{
    free(content);
}