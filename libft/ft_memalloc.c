#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*t;
	size_t	i;

	i = 0;
	t = malloc(size);
	if (!t)
		return (NULL);
	while (i < size)
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}
