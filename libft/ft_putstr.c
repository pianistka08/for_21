#include "libft.h"

void		ft_putstr(char const *s)
{
	int		l;

	l = ft_strlen(s);
	write(1, s, l);
}
