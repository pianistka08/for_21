#include "libft.h"

void		print(char **arr)
{
	int		i;

	if (arr == NULL)
	{
		return ;
	}
	i = 0;
	while (arr[i] != 0)
	{
		ft_putendl(arr[i]);
		i++;
	}
}
