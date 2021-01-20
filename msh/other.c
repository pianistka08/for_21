/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:14:56 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/18 16:21:37 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

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

t_list				*make_new(void)
{
	t_list			*new;

	new = (t_list *)malloc(sizeof(t_list));
	new->next = NULL;
	return (new);
}

int					test_quot(char **s)
{
	int				i;
	int				c;
	int				q2;
	int				q1;

	i = 1;
	q2 = 0;
	q1 = 0;
	c = 0;
	while (s[i] != '\0')
	{
		c = 0;
		while (s[i][c] != '\0')
		{
			if (s[i][c] == '"')
				q2++;
			if (s[i][c] == 39)
				q1++;
			c++;
		}
		i++;
	}
	if (q2 % 2 > 0 || q1 % 2 > 0)
		return (0);
	return (1);
}

void				sh_clear(void)
{
	write(1, " \e[1;1H\e[2J", 12);
}

void				print_promt(void)
{
	ft_putstr("\033[1;36m");
	ft_putstr("shell_hog> \033[0m");
}
