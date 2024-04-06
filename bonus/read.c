#include "puch_swap_bonus.h"
void prtint_stak( t_list  *stak_a)
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

int chek_sort(t_list *stak_a)
{
    t_list *help;
    int count;

    count = 1;
    help = stak_a;
    while(help->next)
    {
        if( *(int*)help->content < *(int*)help->next->content)
            count++;
        help = help->next;
    }
    if(ft_lstsize(stak_a) == count)
        return(0);
    else
        return(1);
}

char 	*checker(void)
{
	char	*line;
	char *str = NULL;
	char *temp;

	line = get_next_line(0);
	while (line)
	{
		temp = str;
		str = ft_strjoin(str, line);
		free(temp);
		line = get_next_line(0);
	}
	free(line);
	return(str);
}

void  cheeek_sort(t_list  **stak_a , t_list  **stak_b)
{
	char **split;

	split = ft_split(checker(), '\n');
	while(*split)
	{
		if(ft_strncmp(*split, "sa",ft_strlen(*split)) == 0)
			sa(stak_a, 'a');
		if(ft_strncmp(*split, "sb",ft_strlen(*split)) == 0)
			sa(stak_b, 'b');
		if(ft_strncmp(*split, "ss",ft_strlen(*split)) == 0)
			ss(stak_a, stak_b);
		if(ft_strncmp(*split, "pa",ft_strlen(*split)) == 0)
			pa(stak_a, stak_b);
		if(ft_strncmp(*split, "pb",ft_strlen(*split)) == 0)
			pb(stak_a, stak_b);
		if(ft_strncmp(*split, "ra",ft_strlen(*split)) == 0)
			ra(stak_a);
		if(ft_strncmp(*split, "rb",ft_strlen(*split)) == 0)
			rb(stak_b);
		if(ft_strncmp(*split, "rr",ft_strlen(*split)) == 0)
			rr(stak_a, stak_b);
		if(ft_strncmp(*split, "rra",ft_strlen(*split)) == 0)
			rra(stak_a);
		if(ft_strncmp(*split, "rrb",ft_strlen(*split)) == 0)
			rrb(stak_b);
		if(ft_strncmp(*split, "rrr",ft_strlen(*split)) == 0)
			rrr(stak_a, stak_b);
		split++;
	}
	if(chek_sort(*stak_a) == 0 && ft_lstsize(*stak_b) == 0)
		write(1, "OK\n", 3);
	
	else
		write(1, "KO\n", 3);
}