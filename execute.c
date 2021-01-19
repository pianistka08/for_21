#include "sh.h"

void			do_proc(int read, int fd, t_cmd *cmd)
{
	pid_t		pid;
	extern char **environ;

	if ((pid = fork()) == 0)
	{
		if (read != 0 && cmd->prev->type == 2)
		{
			dup2(read, 0);
			close(read);
		}
		if (fd != 1 && cmd->type == 2)
		{
			dup2(fd, 1);
			close(fd);
		}
		if (execve(cmd->arr[0], cmd->arr, environ) == -1)
			ft_putendl(" execve error");
	}
	else
		wait(&pid);
}

void			execute(t_cmd *cmd)
{
	int			read;
	int			fd[2];

	read = 0;
	while(cmd)
	{
		pipe(fd);
		do_proc(read, fd[1], cmd);
		close(fd[1]);
		read = fd[0];
		cmd = cmd->next;
	}
}

