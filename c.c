#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void *free_split(char **split)
{
	int i  = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

int main()
{

	char **a = ft_tokenize("Hello World How are You");


	free_split(a);
}
