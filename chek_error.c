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
                return(0);
            help = help->next;
        }
        stak_a = stak_a->next;
    }
    return(1);
}
void del(void* content)
{
    free(content);
}