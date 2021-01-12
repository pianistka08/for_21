#include "sh.h"

void			redirect_great(t_cmd *t)
{
	int			fd[2];
	extern char	**environ;

	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		if (execve(t->arr[0], t->arr, environ) == -1)
			ft_putendl(" execve error");
	}
	if (fork() == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		if (execve(t->next->arr[0], t->next->arr, environ) == -1)
			ft_putendl(" execve error");
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void			execute(t_cmd *t)
{
	if (t->type)
		redirect_great(t);
}

