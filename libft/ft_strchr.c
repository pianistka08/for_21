#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
