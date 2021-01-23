#include "sh.h"

char				*get_name(char *s)
{
	int				l;
	char			*name;
	int				i;
	int				c;

	i = 1;
	c = 0;
	l = ft_strlen(s);
	name = (char *)malloc(sizeof(char) * l);
	while (s[i])
		name[c++] = s[i++];
	name[c] = '\0';
	return (name);
}

void			echo_env(char *s, t_list *env, int fd)
{
	char		*name;
	t_list		*cur;

	cur = env;
	name = get_name(s);
	while (cur)
	{
		if (ft_strcmp(name, cur->name) == 0)
		{
			ft_putstr_fd(cur->val, fd);
			break ;
		}
		cur = cur->next;
	}
	free(name);
}

void			print_echo(char *s, int fd)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '"' && s[i] != 39)
			ft_putchar_fd(s[i], fd);
		i++;
	}
}

void			sh_echo(t_cmd *cmd, int fd)
{
	int			i;
	int			sp;
	t_list			*env;

	env = env_list();
	sp = ft_strsplit_len(cmd->arr) - 1;
	i = 1;
	while (cmd->arr[i])
	{
		if (cmd->arr[i][0] == '$')
			echo_env(cmd->arr[i], env, fd);
		else
			print_echo(cmd->arr[i], fd);
		if (sp--)
			ft_putchar_fd(' ', fd);
		i++;
	}
	write(2, "\n", 1);
}

void			sh_env(int fd)
{
	extern char **environ;
	int			i;

	i = 0;
	while (environ[i])
	{
		ft_putendl_fd(environ[i], fd);
		i++;
	}
}

void				sh_clear(void)
{
	write(1, " \e[1;1H\e[2J", 12);
}

int				do_builtin(t_cmd *cmd)
{
	t_list			*env;

	env = env_list();
	/*if (ft_strcmp(cmd->arr[0], ECHO) == 0)
		sh_echo(cmd, 1);*/
	if (ft_strcmp(cmd->arr[0], EXIT) == 0)
	{
		return (0);
	}
	if (ft_strcmp(cmd->arr[0], CLEAR) == 0)
		sh_clear();
	if (ft_strcmp(cmd->arr[0], SETENV) == 0)
		sh_setenv(cmd->arr, env);
	if (ft_strcmp(cmd->arr[0], UNSETENV) == 0)
		sh_unset(cmd->arr, env);
	if (ft_strcmp(cmd->arr[0], CD) == 0)
		sh_cd(cmd->arr, env);
	clear_list(env);
	return (1);
}
