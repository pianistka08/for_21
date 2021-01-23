#include "sh.h"

void			sh_pwd(char **cmd)
{
	char		dir[256];

	if (cmd[1] == '\0')
	{
		getcwd(dir, 256);
		ft_putendl(dir);
	}
	if (cmd[1] != '\0')
		ft_putendl_fd("pwd: too many arguments", 2);
}

void			mis_cd(char *p, int sig)
{
	if (sig == 1)
	{
		ft_putstr_fd(p, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	if (sig == 2)
		ft_putendl_fd("cd: Too many arguments.", 2);
	if (sig == 3)
		ft_putendl_fd(": No such file or directory.", 2);
	if (sig == 4)
		ft_putendl_fd("It`s nothing set for HOME.", 2);
}

char			*get_post(char *s)
{
	int			i;
	int			j;
	int			l;
	char		*res;

	i = 0;
	j = 1;
	l = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * l);
	while (s[j] != '\0')
	{
		res[i] = s[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}


void			cd_rev(t_list *env)
{
	char		*name;
	char		*oname;
	t_list		*cur;

	cur = env;
	while (cur)
	{
		if (ft_strcmp("PWD", cur->name) == 0)
			name = ft_strdup(cur->val);
		if (ft_strcmp("OLDPWD", cur->name) == 0)
			oname = ft_strdup(cur->val);
		cur = cur->next;
	}
	if (ft_strcmp(name, oname) == 0)
		mis_cd(NULL, 3);
	if (ft_strcmp(name, oname) != 0)
	{
		sh_setnew("OLDPWD", name, env);
		chdir(oname);
		sh_setnew("PWD", oname, env);
		free(name);
		free(oname);
	}
}

void			cd_home(t_list *env)
{
	t_list		*cur;
	char		*way;
	char		dir[256];

	way = NULL;
	cur = env;
	getcwd(dir, 256);
	while (cur)
	{
		if (ft_strcmp("HOME", cur->name) == 0)
		{
			way = ft_strdup(cur->val);
			break ;
		}
		cur = cur->next;
	}
	sh_setnew("OLDPWD", dir, env);
	chdir(way);
	getcwd(dir, 256);
	sh_setnew("PWD", dir, env);
	free(way);
}

void			cd_cd(char *way, t_list *env)
{
	char		dir[256];
	char		ndir[256];
	int			sig;

	getcwd(dir, 256);
	sig = chdir(way);
	if (sig < 0)
		mis_cd(NULL, 1);
	if (sig == 0)
	{
		getcwd(ndir, 256);
		sh_setnew("PWD", ndir, env);
		sh_setnew("OLDPWD", dir, env);
	}
}

void			path_from_home(char *way, t_list *env)
{
	char		*way1;
	t_list		*cur;
	char		*post;

	post = get_post(way);
	way1 = NULL;
	cur = env;
	while (cur)
	{
		if (ft_strcmp("HOME", cur->name) == 0)
		{
			way1 = ft_strdup(cur->val);
			break ;
		}
		cur = cur->next;
	}
	ft_strcat(way1, post);
	cd_cd(way1, env);
	free(way1);
	free(post);
}

void			sh_cd(char **cmd, t_list *env)
{
	if (cmd[1] == NULL)
		cd_home(env);
	else if (cmd[1][0] == '~' && cmd[1][1] == '\0')
		cd_home(env);
	else if (cmd[1][0] == '~' && cmd[1][1] != '\0')
		path_from_home(cmd[1], env);
	else if (cmd[1][0] == '-')
		cd_rev(env);
	else if (cmd[1][0] != '~' && cmd[1][0] != '-')
		cd_cd(cmd[1], env);
	else if (cmd[2] != NULL)
		mis_cd(NULL, 2);
}
