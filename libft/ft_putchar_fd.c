#include "libft.h"

void	ft_putchar_fd(char const c, int fd)
{
	write(fd, &c, 1);
}
