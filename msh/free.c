/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassunta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 14:07:18 by cassunta          #+#    #+#             */
/*   Updated: 2020/09/14 09:12:23 by cassunta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list				*clear_list(t_list *env)
{
	t_list			*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->name);
		tmp->name = NULL;
		free(tmp->val);
		tmp->val = NULL;
		free(tmp);
		tmp = NULL;
	}
	free(env);
	return (NULL);
}

void				free_all(char ***arr)
{
	int				i;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
