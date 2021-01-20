#include "sh.h"

t_cmd			*init_cmd(void)
{
	t_cmd		*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->arr = NULL;
	new->type = -1;
	new->r_type = -1;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_cmd			*new_cmd(t_cmd *prev)
{
	t_cmd		*new;

	new = init_cmd();
	new->prev = prev;
	return (new);
}