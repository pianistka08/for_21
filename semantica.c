#include "sh.h"

char 				*get_semantica_ret(char *line, int *i, char *res, int j)
{
	char			*ret;

	ret = NULL;
	if (line[*i] == ';')
	{
		res[j + 1] = '\0';
		ret = ft_strtrim(ft_strdup(res));
		return (ret);
	}
	if (line[*i] == '|')
	{
		ret = if_vertical_bar(line, i, res, j);
		return (ret);
	}
	if (line[*i] == '&')
	{
		ret = if_ampersand(line, i, res, j);
		return (ret);
	}
}

int 				semantica(t_flag *flag, char *line, int *i, int *j)
{
	if (((flag->d_quot > 0) && (flag->d_quot % 2 != 0)) || ((flag->u_quot > 0)
	&& (flag->u_quot % 2 != 0)) || /// если открыты кавычки или есть бек-слэш
		(line[*i - 1] && line[*i - 1] == 92))
	{
		*i += 1;
		*j += 1;
		return (0);
	}
	if (line[*i] == '&')
	{
		if ((line[*i - 1] && (line[*i - 1] == '<' || line[*i - 1] == '>')) ||
				(line[*i + 1] && (line[*i + 1] == '<' || line[*i + 1] == '>')))
		{
			*i += 1;
			*j += 1;
			return (0);
		}
	}
	if (*j != 0 || ((flag->d_quot % 2 != 0) || (flag->u_quot % 2 != 0) || /// если открыты кавычки или есть бек-слэш
		(line[*i - 1] && line[*i - 1] != 92)))
		return (1);
	if (*j == 0)
		return (2);
}