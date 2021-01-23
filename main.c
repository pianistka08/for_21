#include "sh.h"

int				main()
{
	t_token		*token;
	char		*line;
	t_cmd		*cmd;

	token = NULL;
	line = NULL;
	get_next_line(0, &line);
	token = parsing_t(line);
	cmd = get_cmd(token);
	execute(cmd);
	return (0);
}
