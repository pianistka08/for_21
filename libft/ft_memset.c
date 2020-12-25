#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*a;

	i = 0;
	a = (char *)b;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (b);
}
