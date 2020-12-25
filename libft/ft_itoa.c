#include "libft.h"

static int		ft_size(int n)
{
	int			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*s;
	long int	nb;
	int			size;
	int			sign;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		nb = -(nb);
	}
	size = ft_size(n);
	s = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	s[sign + size] = '\0';
	while (size--)
	{
		s[size + sign] = (nb % 10) + '0';
		nb /= 10;
	}
	return (s);
}
