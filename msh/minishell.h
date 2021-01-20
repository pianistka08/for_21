#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define ECHO "echo"
# define CD "cd"
# define SETENV "setenv"
# define UNSETENV "unsetenv"
# define ENV "env"
# define PWD "pwd"
# define EXIT "exit"
# define CLEAR "clear"

typedef struct		s_list
{
	char			*name;
	char			*val;

	struct s_list	*next;
}					t_list;

int					sh_setnew(char *nm, char *val, t_list *env);
void				sh_setenv(char **cmd, t_list *env);
t_list				*sh_unset(char **nm, t_list *env);
void				echo_env(char *s, t_list *env);
void				sh_echo(char **cmd, t_list *env);
void				sh_env(t_list *env);
void				sh_pwd(char **cmd);
char				*get_name(char *s);
void				find_cmd(char **cmd, t_list *env);
void				print_promt(void);
void				get_env(t_list *env);
void				sh_loop();
void				sh_cd(char **cmd, t_list *env);
void				mis_cd(char *p, int sig);
void				new_process(char **cmd, t_list *env);
void				sh_clear();
void				sh_exit(void);
void				free_all(char ***arr);
t_list				*clear_list(t_list *env);
t_list				*make_new(void);
int					arr_len(char **arr);
char				*get_env_name(char *s);
int					test_quot(char *s);
char				*get_post(char *s);
void				only_sp(char **line, char target, char change);
int					are_empty(char *line);
char				*copy_in_str(char *s1, char *s2);
int					is_it_avalible(char *s);
char				**get_ways(t_list *env);

#endif
