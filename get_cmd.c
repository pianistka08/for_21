#include "sh.h"

t_cmd			*get_data_cmd(t_token *t, t_cmd *d)
{
	d->arr = ft_strsplit(t->data, ' ');
	if (t->next)
		d->type = t->next->c_type;
	return (d);
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
			cur_t = cur_t->next->next;
			cur->next = new_cmd(cur);
			cur = cur->next;
		}
		else
			break ;
	}
	return (head);
}
