/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:14:08 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/18 16:23:05 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			echo_env(char *s, t_list *env)
{
	char		*name;
	t_list		*cur;

	cur = env;
	name = get_name(s);
	while (cur)
	{
		if (ft_strcmp(name, cur->name) == 0)
		{
			ft_putstr(cur->val);
			break ;
		}
		cur = cur->next;
	}
	free(name);
}

void			print_echo(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '"' && s[i] != 39)
			ft_putchar(s[i]);
		i++;
	}
}

void			sh_echo(char **cmd, t_list *env)
{
	int			i;
	int			sp;
	int			quot;

	quot = test_quot(cmd);
	if (quot)
	{
		sp = arr_len(cmd) - 1;
		i = 1;
		while (cmd[i])
		{
			if (cmd[i][0] == '$')
				echo_env(cmd[i], env);
			else
				print_echo(cmd[i]);
			if (sp--)
				ft_putchar(' ');
			i++;
		}
	}
	if (!quot)
		ft_putstr("Unmatched quots.");
	write(1, "\n", 1);
}

void			sh_env(t_list *env)
{
	t_list		*cur;

	cur = env;
	while (cur)
	{
		ft_putstr(cur->name);
		ft_putchar('=');
		ft_putendl(cur->val);
		cur = cur->next;
	}
}
