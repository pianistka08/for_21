#include "sh.h"

char			*new_string(char *s)
{
	char		*n;
	int			i;

	i = ft_strlen(s);
	n = (char *)malloc(sizeof(char) * i);
	while (i >= 0)
	{
		n[i] = '\0';
		i--;
	}
	return (n);
}

char				*get_value(char *s, t_list *env)
{
	t_list			*cur;
	char			*res;

	cur = env;
	while (cur)
	{
		if (ft_strcmp(s, cur->name) == 0)
		{
			res = ft_strdup(cur->val);
			return (res);
		}
		cur = cur->next;
	}
	return (NULL);
}

char				*getter_of_val(char *s)
{
	t_list			*env;
	char			*res;

	env = env_list();
	res = get_value(s, env);
	clear_list(env);
	return (res);
}

static void			get_env_val(char *buf, int *j, char *t, int *i)
{
	char			tmp[246];
	int				u;
	char			*t_tmp;
	char			*f;

	u = 0;
	*i = *i + 1;
	while (t[*i] != ' ' && t[*i] != '/' && t[*i] != 92
	&& t[*i] != 34 && t[*i] !=39 && t[*i])
	{
		tmp[u] = t[*i];
		*i = *i + 1;
		u++;
	}
	tmp[u] = '\0';
	f = ft_strdup(tmp);
	t_tmp = getter_of_val(f);
	if (t_tmp)
	{
		u = 0;
		while (t_tmp[u])
		{
			buf[*j] = t_tmp[u];
			*j = *j + 1;
			u++;
		}
	}
	free(f);
	free(t_tmp);
}

t_cmd			*get_data_cmd(t_token *t, t_cmd *c)
{
	int			i;
	int 		q[2]; /// 0 для одинарного, 1 для двойного
	char		*buf;
	int			j;

	i = 0;
	j = 0;
	q[0] = 0;
	q[1] = 0;
	buf = new_string(t->data);
	while (t->data[i])
	{
		if (t->data[i] != 34 && t->data[i] != 39)
			buf[j++] = t->data[i++];
		if (t->data[i] == 39 && q[1] == 0)
		{
			q[0] = 1;
			i++;
			while (t->data[i] != 39)
			{
				buf[j] = t->data[i];
				j++;
				i++;
			}
			if(t->data[i] == 39 && q[0] == 1)
			{
				q[0] = 0;
				i++;
			}
		}
		if (t->data[i] == 34)
		{
			q[1] = 1;
			i++;
			while (t->data[i] != 34)
			{
				if (t->data[i] == '&' && (t->data[i - 1] && t->data[i - 1] != 92))
					get_env_val(buf, &j, t->data, &i);
				buf[j] = t->data[i];
				j++;
				i++;
			}
		}
		if (t->data[i] == '$' && t->data[i - 1] && t->data[i - 1] != 92)
			get_env_val(buf, &j, t->data, &i);
	}
	c->arr = ft_strsplit(buf, ' ');
	free(buf);
	return (c);
}

t_cmd			*get_cmd(t_token *t)
{
	t_token		*cur_t;
	t_cmd		*head;
	t_cmd		*cur;


	cur_t = t;
	head = init_cmd();
	cur = head;
	while (cur_t)
	{
		cur = get_data_cmd(cur_t, cur);
		if (cur_t->next && cur_t->next->next)
		{
			cur->type = cur_t->next->c_type;
			cur_t = cur_t->next->next;
			cur->next = new_cmd(cur);
			cur = cur->next;
		}
		else
			break ;
	}
	return (head);
}
