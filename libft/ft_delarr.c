#include "libft.h"

void		ft_delmap(char **arr, int size)
{
	while (--size >= 0)
		free(arr[size]);
	free(arr);
}
