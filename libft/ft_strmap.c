#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*m_str;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	m_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (m_str == NULL)
		return (NULL);
	while (s[i])
	{
		m_str[i] = f(s[i]);
		i++;
	}
	m_str[i] = '\0';
	return (m_str);
}
