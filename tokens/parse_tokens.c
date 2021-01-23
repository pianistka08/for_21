#include "sh.h"

char 				*get_data(char *line, int *n, t_flag *flag)
{
	char 			res[1000];
	int 			j;
	char			*ret;
	char			*buf;

	j = 0;
	while (line[*n] != '\0')
	{
		while (line[*n] != '|' && line[*n] != ';' && line[*n] != '&' && line[*n] != '>' &&
			   line[*n] != '<'  && line[*n] != '\0')
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
				buf = ft_strdup(res);
				ret = ft_strtrim(buf);
				free(buf);
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
	buf = ft_strdup(res);
	ret = ft_strtrim(buf);
	free(buf);
	return (ret);
}

t_token 			*parsing_t(char *line)
{
	t_token *token;
	int car;
	t_flag *flag;
	int l;
	t_token *cur;
	t_cmd *cmd;


	car = 0;
	l = ft_strlen(line);
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
	free(flag);
	//free(line);
	/*if (is_tokens_true(cur))
	{
		cmd = get_cmd(cur);
		execute(cmd);
	}
	free_token(cur);*/
	return (cur); /// интовая функция, возвращающая значение. специальное значение для exit.
}
