#include "libft.h"

int			ft_wordcount(char const *s, char c)
{
	int		i;
	int		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}
