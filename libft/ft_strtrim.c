#include "libft.h"

static	int		ft_lenstr(char const *s)
{
	int			i;
	int			c;

	c = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	while ((s[i - 1] == ' ') || (s[i - 1] == '\t') || (s[i - 1] == '\n'))
		i--;
	while ((s[c] == ' ') || (s[c] == '\t') || (s[c] == '\n'))
	{
		c++;
		i--;
	}
	return (i);
}

static char		*ft_make_copy(char const *s, char *str, int len)
{
	int			i;
	int			c;

	i = 0;
	c = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
		i++;
	while (c < len)
	{
		str[c] = s[i];
		i++;
		c++;
	}
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	int			len;

	if (s == NULL)
		return (NULL);
	len = ft_lenstr(s);
	if (len <= 0)
		len = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (ft_make_copy(s, str, len));
}
