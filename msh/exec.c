/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:08:30 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/16 13:00:15 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char			*copy_in_str(char *s1, char *s2)
{
	int			len;
	char		*res;
	int			i;
	int			c;

	i = 0;
	c = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	res = (char *)malloc(sizeof(char) * len);
	while (s1[c])
		res[i++] = s1[c++];
	res[i++] = '=';
	c = 0;
	while (s2[c])
		res[i++] = s2[c++];
	res[i] = '\0';
	return (res);
}*/

/*char			**list_to_arr(t_list *env)
{
	char		**arr;
	int			i;
	t_list		*cur;

	cur = env;
	arr = NULL;
	i = 1;
	while (env)
	{
		env = env->next;
		i++;
	}
	arr = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (cur)
	{
		arr[i++] = copy_in_str(cur->name, cur->val);
		cur = cur->next;
	}
	arr[i] = NULL;
	return (arr);
}*/

/*char			*it_path(char *s, t_list *env)
{
	char		**way;
	int			i;

	i = 0;
	way = get_ways(env);
	if (way == NULL)
		return (s);
	else if (way)
	{
		while (way[i] != NULL)
		{
			ft_strcat(way[i], "/");
			ft_strcat(way[i], s);
			if (access(way[i], F_OK) != -1)
			{
				free(s);
				s = ft_strdup(way[i]);
				break ;
			}
			i++;
		}
	}
	free_all(&way);
	return (s);
}*/

/*void			new_process(char **cmd, t_list *env)
{
	//char		**envp;
	char		*path;
	//pid_t		pid;
	int			res;
	extern char **environ;

	res = 0;
	//envp = list_to_arr(env);
	path = ft_strdup(cmd[0]);
	if (path[0] != '/')
		path = it_path(path, env);
	res = is_it_avalible(path);
	if (res > 0)
	{
	if (execve(path, cmd, environ) == -1)
		ft_putendl(" execve error");
	}
	free(path);
	//free_all(&envp);
}*/
