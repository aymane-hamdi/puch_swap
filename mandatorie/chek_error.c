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

int delete_double(t_list *stak_a)
{
    t_list *help;

    while(stak_a)
    {
        help = stak_a->next;
        while(help)
        {
            if (*(int*)(stak_a->content) == *(int*)(help->content))
                return(1);
            help = help->next;
        }
        stak_a = stak_a->next;
    }
    return(0);
}

int chek_sort(t_list *stak_a)
{
    t_list *help;
    int count;

    count = 1;
    help = stak_a;
    while(help->next)
    {
        if(*(int*)help->content < *(int*)help->next->content)
            count++;
        help = help->next;
    }
    if(ft_lstsize(stak_a) == count)
        return(1);
    else
        return(0);
}

int chek_sort_inverse(t_list *stak_a)
{
    t_list *help;
    int count;

    count = 1;
    help = stak_a;
    while(help->next)
    {
        if( *(int*)help->content > *(int*)help->next->content)
            count++;
        help = help->next;
    }
    if(ft_lstsize(stak_a) == count)
        return(1);
    else
        return(0);
}
void error(t_list  **stak_a)
{
    free_stack(stak_a);
    ft_putstr_fd("Error\n",2);
    exit(1);
}