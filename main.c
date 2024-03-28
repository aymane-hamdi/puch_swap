#include"push_swap.h"
void ptint_stak(int *stak_a, int len)
{
    int i;

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
    int *stak_a;
    int len;
    int j ;

    i = 0;
    j = 0;
    if(argc == 2)
    {
        len = ft_count_words(argv[1], ' ');
        argv = ft_split(argv[1],' ');
        i = -1;
    }

    if(argc > 2)
    {
        len = argc - 1;
        stak_a = malloc(sizeof(int) * len);
        if(!stak_a)
            return (0);
    }   
    if(argc == 2)
    { 
        stak_a = malloc(sizeof(int) * len);
        if(!stak_a)
            return (0);
    }
    while(argv[++i])
    {
        if(cheek(argv[i]) == 1)
            stak_a[j] = ft_atoi(argv[i]);
        else
        {
            write(1,"Error\n",6);
            exit(1);
        }
        j++;
    }
    delete_double(&stak_a,&len);
    ptint_stak(stak_a,len);
}