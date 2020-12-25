#include "sh.h"

char 				*get_data(char *line, int *n, t_flag *flag)
{
	char 			res[1000];
	int 			j;
	char			*ret;

	j = 0;
	while (line[*n] != '\0')
	{
		while (line[*n] != '|' && line[*n] != ';' && line[*n] != '&' && line[*n] != '\0')
		{
			update_flag(flag, line[*n]);
			res[j] = line[*n];
			*n += 1;
			j += 1;
		}
		if (line[*n] == '|' || line[*n] == ';' || line[*n] == '&' || line[*n] == '\0')
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

int 			main(void)
{
	t_token		*token;
	char 		*line;
	int 		car;
	t_flag		*flag;
	int 		l;
	t_tree		*tree;
	t_token 	*cur;

	line = NULL;
	car = 0;
	get_next_line(0, &line);
	l = ft_strlen(line);
	line[l] = '\0';
	token = init_token();
	cur = token;
	flag = init_flag();
	token->data = get_data(line, &car, flag);
	while (car < l)
	{
		token->next = init_token();
		token->next->prev = token;
		token = token->next;
		token->data = get_data(line, &car, flag);
		if (ft_strcmp(token->data, "") == 0)
			token->data = get_data(line, &car, flag);
		flag = reset_flag(flag);
	}
	if (is_tokens_true(cur))
		ft_putendl("true");
	tree = get_tree(cur);
	ft_putendl(line);
	return (0);
}