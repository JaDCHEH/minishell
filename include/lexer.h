#ifndef LEXER_H
# define LEXER_H
# include "../libft/libft.h"

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*content;
}	t_lexer;

typedef struct s_token
{
	enum
	{
		TOKEN_FLAG,
		TOKEN_ARG,
		TOKEN_S_QUOTE,
		TOKEN_D_QUOTE,
		TOKEN_PIPE,
		TOKEN_L_THAN,
		TOKEN_DL_THAN,
		TOKEN_G_THAN,
		TOKEN_DG_THAN,
		TOKEN_FILE,
	} e_type;
	char	*value;
}	t_token;

t_lexer	*init_lexer(char *content);
t_token *init_token(int e_type, char	*value);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_whitespaces(t_lexer	*lexer);
t_token	*lexer_get_next_token(t_lexer *lexer);
t_token	*lexer_collect_flag(t_lexer *lexer);
t_token	*lexer_collect_id(t_lexer *lexer);
t_token	*lexer_collect_cmp(t_lexer *lexer, char c);
t_token *lexer_collect_string(t_lexer *lexer, char c);
t_token	*lexer_advance_with_token(t_lexer *lexer, t_token *token);
char	*lexer_get_current_char_as_string(t_lexer *lexer);


#endif