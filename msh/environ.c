/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:20:16 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/14 14:50:54 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					sh_setnew(char *nm, char *val, t_list *env)
{
	if (val == NULL)
		return (0);
	while (env)
	{
		if (ft_strcmp(nm, env->name) == 0)
		{
			free(env->val);
			env->val = ft_strdup(val);
			return (1);
		}
		if (env->next == NULL)
		{
			if (!(env->next = (t_list *)malloc(sizeof(t_list))))
				return (0);
			env = env->next;
			env->name = ft_strdup(nm);
			env->val = ft_strdup(val);
			env->next = NULL;
			return (1);
		}
		env = env->next;
	}
	return (1);
}

void				sh_setenv(char **cmd, t_list *env)
{
	if (cmd[1] == NULL)
		sh_env(env);
	else if (cmd[3] != '\0')
	{
		ft_putendl("setenv% TOO few arguments");
		ft_putendl("Usage: setenv <variable> <value>");
	}
	else if (!(sh_setnew(cmd[1], cmd[2], env)))
	{
		ft_putstr("setenv: nothing to set for this variable ");
		ft_putendl(cmd[1]);
	}
}

void				do_unset(t_list *env, char *nm)
{
	t_list			*tmp;

	tmp = env->next;
	while (tmp)
	{
		if (ft_strcmp(nm, tmp->name) == 0)
		{
			free(tmp->name);
			tmp->name = NULL;
			free(tmp->val);
			tmp->val = NULL;
			env->next = env->next->next;
			free(tmp);
			break ;
		}
		env = env->next;
		tmp = tmp->next;
	}
}

t_list				*sh_unset(char **nm, t_list *env)
{
	t_list			*cur;
	int				i;

	i = 1;
	cur = env;
	while (nm[i] != NULL)
		do_unset(env, nm[i++]);
	return (cur);
}
