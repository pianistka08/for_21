/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:36:16 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/16 12:38:00 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
