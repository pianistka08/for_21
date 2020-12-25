#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t c;

	i = 0;
	c = 0;
	while (s1[i] != '\0')
		i++;
	while ((s2[c] != '\0') && (c < n))
	{
		s1[i] = s2[c];
		i++;
		c++;
	}
	s1[i] = '\0';
	return (s1);
}
