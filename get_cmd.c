#include "sh.h"

/*int				is_redirect_here(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '<' || s[i] == '>')
		{
			if (s[i - 1] && s[i - 1] != 92)
				return (1);
		}
		i++;
	}
}

t_cmd			*data_for_exp(t_token *t, t_cmd *cmd)
{
	if (!is_redirect_here(t->data))
		cmd->arr = ft_strsplit(t->data);
	//else
		//cmd = get_data_with_redirect(t->data, cmd);
	return (cmd);
}

t_cmd			*get_data_cmd(t_token *t, t_cmd *cmd)
{
	if (t->type == 2)
		cmd = data_for_exp(t, cmd);
	if (t->type == 1)
	{
		if (cmd->prev)
	}
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
	}
	return ();
}*/

