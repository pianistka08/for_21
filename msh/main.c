/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:02:54 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/19 11:28:55 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include "minishell.h"

void				sh_exit(void)
{
	exit(EXIT_SUCCESS);
}

void				find_cmd(char **cmd, t_list *env)
{
	if (ft_strcmp(cmd[0], PWD) == 0)
		sh_pwd(cmd);
	if (ft_strcmp(cmd[0], ECHO) == 0)
		sh_echo(cmd, env);
	if (ft_strcmp(cmd[0], ENV) == 0)
		sh_env(env);
	if (ft_strcmp(cmd[0], SETENV) == 0)
		sh_setenv(cmd, env);
	if (ft_strcmp(cmd[0], UNSETENV) == 0)
		sh_unset(cmd, env);
	if (ft_strcmp(cmd[0], CD) == 0)
		sh_cd(cmd, env);
	if (ft_strcmp(cmd[0], EXIT) == 0)
	{
		free_all(&cmd);
		env = clear_list(env);
		sh_exit();
	}
	if (ft_strcmp(cmd[0], CLEAR) == 0)
		sh_clear();
}

int					command(char *s)
{
	if ((ft_strcmp(s, PWD) == 0) || (ft_strcmp(s, ECHO) == 0) ||
		(ft_strcmp(s, ENV) == 0) || (ft_strcmp(s, SETENV) == 0) ||
		(ft_strcmp(s, UNSETENV) == 0) || (ft_strcmp(s, CD) == 0) ||
		(ft_strcmp(s, EXIT) == 0) || (ft_strcmp(s, CLEAR) == 0))
		return (1);
	else
		return (0);
}

void				sh_loop(void)
{
	char			*cline;
	t_list			*env;
	t_cmd			*t;

	env = make_new();
	get_env(env);
	sh_clear();
	while (1)
	{
		print_promt();
		get_next_line(0, &cline);
		only_sp(&cline, '\t', ' ');
		if (ft_strcmp(cline, "") == 0 || are_empty(cline))
		{
			free(cline);
			continue;
		}
		t = parse_p(cline);
	}
}

int					main(void)
{
	sh_loop();
	return (0);
}
