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


int	ft_count_words(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == sep)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (count);
}


void delete_double(int **stak_a ,int *len)
{
    int i = 0;
    int j;
    int len1 = 0;
    int *new_stak;
    while(i < *len -1)
    {
        j = i + 1;
        while(j < *len)
        {
            if((*stak_a)[i] == (*stak_a)[j])
            {
                (*stak_a)[i] = 0;
                len1++;
            }
            j++;
        }
        i++;
    }
    new_stak = malloc(sizeof(int) * (*len - len1));
    if(!new_stak)
        exit(1);
    i = 0;
    j = 0;
    while (i < *len)
    {
        if((*stak_a)[i]!= 0)
            new_stak[j++] = (*stak_a)[i];
        i++;
    }
    free(*stak_a); // Free the old memory
    *stak_a = new_stak; // Assign the new array to stak_a
    *len = *len - len1;
}