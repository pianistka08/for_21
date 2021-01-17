#include "sh.h"

void			simple_exec(t_cmd *cmd, char **env)
{
	pid_t		pid;

	if ((pid = fork()) == 0)
	{
		if (execve(cmd->arr[0], cmd->arr, env) == -1)
			ft_putendl(" execve error");
	}
	wait(&pid);
}

void			do_proc(int read, int fd, t_cmd *cmd, t_list *env)
{
	pid_t		pid;
	char		*path;
	int			res;
	extern char **environ;

	res = 0;
	path = ft_strdup(cmd->arr[0]);
	if (path[0] != '/')
		path = it_path(path, env);
	res = is_it_avalible(path);
	if (res > 0)
	{
		if ((pid = fork()) == 0)
		{
			if (read != 0)
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
}

void			execute(t_cmd *cmd, t_list *env)
{
	int			read;
	int			fd[2];

	read = 0;
	while(cmd)
	{
		pipe(fd);
		do_proc(read, fd[1], cmd, env);
		close(fd[1]);
		read = fd[0];
		cmd = cmd->next;
	}
	if (read != 0)
		dup2(read, 0);
}



