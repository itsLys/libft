#include "libft.h"

int ft_strisnum(char *str)
{
	int i;
	int digit;

	i = +0;
	digit = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i] && ft_isdigit(str[i]))
	{
		digit = 1;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		digit = 1;
		i++;
	}
	if (i == 0 || str[i] || digit == 0)
		return -1;
	return 0;
}

