#ifndef SH_H
#define SH_H

# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "minishell.h"

# include "libft.h"
# define BK "&"
# define AND "&&"
# define OR "||"
# define PIPE "|"
# define SC ";"
# define GREAT ">"
# define GGREAT ">>"
# define LESS "<"
# define LLESS "<<"

extern char	**environ;


typedef enum {
	cmd = 1,
	ext = 2,
}				t_type_token;

typedef enum {
	sc = 1,
	pi = 2,
	and = 3,
	ro = 4,
	bk = 5,
	out_w = 6,
	out_add = 7,
}			t_type_cmd;

typedef struct			s_cmd
{
	char				**arr; //аргументы
	int					fd[2]; // для перенаправлений с конкретного на конкретный дескриптор
	int					r_type; // тип редиректа для редиректа
	int					type; //
	char				*target; // имя файла в случае редиректа
	struct s_cmd		*next;
	struct s_cmd		*prev;
}						t_cmd;

typedef struct 			s_flag
{
	int 				d_quot; /// " кроме $, '', '\'
	int 				u_quot; /// ' отменяет все спецсимволами
}						t_flag;

typedef struct 			s_tree
{
	struct s_token		*token;
	int 				type;
	struct s_tree		*parent;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

typedef struct			s_token
{
	char				*data;
	int				priority;
	int				type;
	int					c_type;
	int					status;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

t_flag				*init_flag(void);
t_flag 				*reset_flag(t_flag *flag);
t_token 			*init_token(void);
t_token 			*put_data_in_new_token(char *line, int *car, t_token *token);
void				update_flag(t_flag *flag, char s);
int 				semantica(t_flag *flag, char *line, int *i, int *j);
int 				is_tokens_true(t_token *t);
t_tree				*get_tree(t_token *token);

void 				*init_tree(void);
void 				*set_child(t_tree *child, t_tree *parent, int f);
t_tree				*get_tree(t_token *token);
t_token 			*get_last_token(t_token *t);

char 			*if_ampersand(char *line, int *i, char *res, int j);
char 			*if_vertical_bar(char *line, int *i, char *res, int j);
char 			*get_semantica_ret(char *line, int *i, char *res, int j);
t_tree				*get_tree(t_token *token);
t_cmd			*get_data_cmd(t_token *t, t_cmd *cmd);
t_cmd			*new_cmd(t_cmd *prev);
t_cmd			*init_cmd(void);
t_cmd			*get_cmd(t_token *t);
t_cmd			*get_data_with_redirect(char *s, t_cmd *cmd);
char			*get_redirect(char *line, int *i, char *res, int j);
void			parse_p(char *line, t_list *env);
void			execute(t_cmd *cmd, t_list *env);

#endif
