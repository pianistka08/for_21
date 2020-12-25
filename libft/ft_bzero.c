#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*s1;

	i = 0;
	s1 = (char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}
