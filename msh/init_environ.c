/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_environ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:41:41 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/14 09:40:13 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*get_env_name(char *s)
{
	char		*nm;
	int			l;
	int			i;

	i = 0;
	l = 1;
	while (s[l] != '=')
		l++;
	nm = (char *)malloc(sizeof(char) * l + 1);
	while (s[i] != '=')
	{
		nm[i] = s[i];
		i++;
	}
	nm[i] = '\0';
	return (nm);
}

int				arr_len(char **env)
{
	int			len;
	int			i;

	len = -1;
	i = 0;
	while (env[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			*get_env_val(char *env, char *val)
{
	int			i;
	int			c;

	i = 0;
	c = 0;
	while (env[i] != '=')
		i++;
	val = (char *)malloc(sizeof(char) * ft_strlen(env) - i);
	i++;
	while (env[i])
		val[c++] = env[i++];
	val[c] = '\0';
	return (val);
}

void			get_env(t_list *env)
{
	extern char	**environ;
	int			i;
	t_list		*cur;
	int			len;

	len = arr_len(environ);
	i = 0;
	cur = env;
	while (environ[i])
	{
		cur->name = get_env_name(environ[i]);
		cur->val = get_env_val(environ[i], cur->val);
		if (len)
		{
			cur->next = make_new();
			cur = cur->next;
		}
		if (!len)
			break ;
		i++;
		len--;
	}
}
