#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_1;
	unsigned char	*s2_2;
	size_t			i;

	i = 0;
	s1_1 = (unsigned char *)s1;
	s2_2 = (unsigned char *)s2;
	if (s1_1 == NULL && s2_2 == NULL)
		return (0);
	while (i < n && s1_1[i] == s2_2[i])
		i++;
	if (i < n && s1_1[i] != s2_2[i])
		return (s1_1[i] - s2_2[i]);
	if (i == n)
		return (0);
	return (0);
}
