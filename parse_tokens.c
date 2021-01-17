#include "sh.h"

char 				*get_data(char *line, int *n, t_flag *flag)
{
	char 			res[1000];
	int 			j;
	char			*ret;

	j = 0;
	while (line[*n] != '\0')
	{
		while (line[*n] != '|' && line[*n] != ';' && line[*n] != '&' && line[*n] != '>' &&
			   line[*n] != '<' && line[*n] != '\0')
		{
			update_flag(flag, line[*n]);
			res[j] = line[*n];
			*n += 1;
			j += 1;
		}
		if (line[*n] == '|' || line[*n] == ';' || line[*n] == '&' || line[*n] == '>' ||
		line[*n] == '<' || line[*n] == '\0')
		{
			res[j] = line[*n];
			if (semantica(flag, line, n, &j) == 0)
				continue ;
			if (semantica(flag, line, n, &j) == 1 && j != 0)
			{
				res[j] = '\0';
				ret = ft_strtrim(ft_strdup(res));
				return (ret);
			}
			if (j == 0)
			{
				ret = get_semantica_ret(line, n, res, j);
				*n += 1;
				return (ret);
			}
		}
	}
	ret = ft_strtrim(ft_strdup(res));
	return (ret);
}

void			execute_cmd_line(char *cmd, t_list *env)
{
	char		**exp;
	int			i;
	t_cmd		*head;
	t_cmd		*cur;

	i = 0;
	head = init_cmd();
	cur = head;
	exp = ft_strsplit(cmd, '|');
	while (exp[i])
	{
		cur->arr = ft_strsplit(exp[i], ' ');
		if (exp[i + 1])
		{
			cur->type = 2;
			cur->next = init_cmd();
			cur->next->prev = cur;
			cur = cur->next;
		}
		i++;
	}
	execute(head, env);
}

void				parse_p(char *line, t_list *env)
{
	char		**cmd_blocks;
	int			i;

	i = 0;
	cmd_blocks = ft_strsplit(line, ';');
	while (cmd_blocks[i])
		{
			execute_cmd_line(cmd_blocks[i], env);
			i++;
		}
	ft_strsplit_free(&cmd_blocks);
}