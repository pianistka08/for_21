#include "sh.h"

void			redirect_great(t_token *t)
{
	int			fd[2];
	char		**cmd;
	char		**cmd2;
	extern char	**environ;

	cmd = ft_strsplit(t->data, ' ');
	cmd2 = ft_strsplit(t->next->next->data, ' ');
	pipe(fd);
	if (fork() == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		if (execve(cmd[0], cmd, environ) == -1)
			ft_putendl(" execve error");
	}
	if (fork() == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		if (execve(cmd2[0], cmd2, environ) == -1)
			ft_putendl(" execve error");
	}
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}

void			execute(t_token *t)
{
	//while (t)
	//{
		if (t->c_type == 0 && (t->next->c_type == 2))
			redirect_great(t);
	//}
}

