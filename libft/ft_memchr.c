#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	const char		*str;

	str = (const char *)s;
	count = -1;
	while (++count < n)
	{
		if (*(str + count) == (char)c)
			return ((void *)s + count);
	}
	return (NULL);
}
