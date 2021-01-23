#include "sh.h"

void			free_token(t_token *t)
{
	t_token		*cur;

	cur = t;
	while (t)
	{
		cur = t;
		t = t->next;
		free(cur->data);
		free(cur);
	}
}

void			free_cmd(t_cmd *cmd)
{
	t_cmd		*cur;

	while (cmd)
	{
		cur = cmd;
		cmd = cmd->next;
		if (cur->arr)
			ft_strsplit_free(&cur->arr);
		if (cur->target != NULL)
			free(cur->target);
		free(cur);
	}
}
