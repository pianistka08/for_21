#include "sh.h"

/*char			*get_target(char *s, int i)
{
	char		buf[1024];
	int			j;
	char		*res;

	j = 0;
	if (s[i] != '&')
	{
		while (s[i] && s[i] != ' ') {
			buf[j] = s[i];
			i++;
			j++;
		}
		buf[j] = '\0';
		res = ft_strdup(buf);
	}
	else
	{
		i++;
		fd2 =
	}
	return (res);
}

t_cmd			*redirect_for_out(char *s, t_cmd *cmd)
{
	int			i;

	i = 0;
	while (s[i] != '>')
		i++;
	cmd->r_type = s[i] == s[i + 1] ? out_add : out_w;
	if (cmd->r_type == out_add)
		i = i + 2;
	if (s[i] == '&')
	cmd->target = get_target(s, i);
}

t_cmd			*get_data_with_redirect(char *s, t_cmd *cmd)
{
	if (ft_strchr(s, '>'))
		cmd = redirect_for_out(s, cmd);
}*/