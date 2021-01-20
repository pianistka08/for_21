/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retouch_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:44:30 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/19 11:31:06 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					is_it_avalible(char *s)
{
	if (access(s, F_OK) == -1)
	{
		ft_putendl("Unavalible command.");
		return (-1);
	}
	return (1);
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
			only_sp(&temp, ' ', ':');
			res = ft_strsplit(temp, ':');
			free(temp);
			break ;
		}
		env = env->next;
	}
	return (res);
}

int					are_empty(char *line)
{
	int				i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (0);
		i++;
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
