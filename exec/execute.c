#include "sh.h"

t_list				*clear_list(t_list *env)
{
	t_list			*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp->val);
		tmp->val = NULL;
		free(tmp);
		tmp = NULL;
	}
	free(env);
	return (NULL);
}

int					is_it_avalible(char *s)
{
	if (access(s, F_OK) == -1)
	{
		ft_putendl("Unavalible command.");
		return (-1);
	}
	return (1);
}

void				only_sp(char **line, char target, char change)
{
	int				i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == target)
			(*line)[i] = change;
		i++;
	}
}

char				**get_ways(t_list *env)
{
	char			**res;
	char			*temp;

	res = NULL;
	while (env != NULL)
	{
		if (ft_strcmp("PATH", env->name) == 0)
		{
			temp = ft_strdup(env->val);
			//only_sp(&temp, ' ', ':');
			res = ft_strsplit(temp, ':');
			free(temp);
			break ;
		}
		env = env->next;
	}
	return (res);
}

char			*it_path(char *s, t_list *env)
{
	char		**way;
	int			i;
	char		*buf;

	buf = NULL;
	i = 0;
	way = get_ways(env);
	if (way == NULL)
		return (s);
	else if (way)
	{
		while (way[i] != NULL)
		{
			buf = ft_strdup(way[i]);
			ft_strcat(buf, "/");
			ft_strcat(buf, s);
			if (access(buf, F_OK) != -1)
				break ;
			i++;
		}
	}
	ft_strsplit_free(&way);
	return (buf);
}

char				*get_path(char *s)
{
	t_list			*env;
	char			*res;

	env = env_list();
	res = it_path(s, env);
	clear_list(env);
	if (is_it_avalible(res))
	{
		return (res);
	}
	free(res);
	return (NULL);
}

int					command(char *s)
{
	if (/*(ft_strcmp(s, ECHO) == 0) ||
		(ft_strcmp(s, ENV) == 0) || */(ft_strcmp(s, SETENV) == 0) ||
		(ft_strcmp(s, UNSETENV) == 0) || (ft_strcmp(s, CD) == 0) ||
		(ft_strcmp(s, EXIT) == 0) || (ft_strcmp(s, CLEAR) == 0))
		return (1);
	else
		return (0);
}

void			do_proc(int read, int fd, char *path, t_cmd *cmd)
{
	pid_t		pid;
	extern char **environ;

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
		if (execve(path, cmd->arr, environ) == -1)
			ft_putendl(" execve error");
		//// как-то завернуть процесс на выход
	}
	else
		wait(&pid);
	free(cmd->target);
}

void			do_target(t_cmd *cmd)
{
	while (cmd)
	{
		if ((!command(cmd->arr[0]) && (int) cmd->arr[0] != '/') ||
			(ft_strcmp(ENV, cmd->arr[0]) == 0 || ft_strcmp(ECHO, cmd->arr[0]) == 0))
		{
			cmd->target = get_path(cmd->arr[0]);
			if (cmd->target == NULL)
				return;
		}
		cmd = cmd->next;
	}
}

int			execute(t_cmd *cmd)
{
	int			read;
	int			fd[2];
	pid_t		pid;
	t_cmd 		*head;
	int			res;

	res = 1;
	head = cmd;
	read = 0;
	do_target(cmd);
	while (cmd)
	{
		if ((pid = fork()) == 0)
		{
			pipe(fd);
			if (command(cmd->arr[0]) && cmd->type != 2)
				res = do_builtin(cmd);
			else
				do_proc(read, fd[1], cmd->target, cmd);
			close(fd[1]);
			read = fd[0];
		}
		else
			wait(&pid);
		cmd = cmd->next;
	}
	//free_cmd(head);
	return (res);
}

