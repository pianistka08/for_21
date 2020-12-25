#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int		result;
	int					sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10 + *str - '0') * sign;
		str++;
	}
	return (result);
}
