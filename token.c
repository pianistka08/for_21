#include "sh.h"

t_token 			*get_last_token(t_token *t)
{
	t_token 		*r;

	r = t;
	while (r->next != NULL)
		r = r->next;
	return (r);
}

int 				right_row(t_token *t)
{
	t_token 		*first;

	first = t;
	while (first->next)
	{
		if (first->type == first->next->type)
			return (0);
		first = first->next;
	}
	return (1);
}

int 				get_priority(char *s)
{
	//if (ft_strcmp(s, BK) == 0)
	//return ()
	if (ft_strcmp(s, OR) == 0)
		return (2);
	if (ft_strcmp(s, AND) == 0)
		return (2);
	if (ft_strcmp(s, PIPE) == 0)
		return (3);
	if (ft_strcmp(s, SC) == 0)
		return (1);
}

int 				is_tokens_true(t_token *t)
{
	t_token 		*tmp;

	tmp = t;
	while (t)
	{
		if (ft_strcmp(t->data, BK) == 0 ||
				ft_strcmp(t->data, OR) == 0 ||
				ft_strcmp(t->data, AND) == 0 ||
				ft_strcmp(t->data, PIPE) == 0 ||
				ft_strcmp(t->data, SC) == 0)
		{
			t->type = cmd;
			t->priority = get_priority(t->data);
		}
		else
			t->type = ext;
		t = t->next;
	}
	if (right_row(tmp))
		return (1);
	else
		return (0);
}

t_token 			*init_token(void)
{
	t_token		*new;

	if(!(new = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	new->data = NULL;
	new->priority = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}