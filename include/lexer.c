#include "lexer.h"

t_lexer	*init_lexer(char *content)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->content = content;
	lexer->i = 0;
	lexer->c = content[lexer->i];
	return (lexer);
}

t_token	*init_token(int type, char	*value)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->e_type = type;
	token->value = value;
	return (token);
}

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer->i++;
		lexer->c = lexer->content[lexer->i];
	}
}

void	lexer_skip_whitespaces(t_lexer	*lexer)
{
	while (lexer->c == ' ' || lexer->c == '\n')
	{
		lexer_advance(lexer);
	}
}

t_token	*lexer_get_next_token(t_lexer *lexer)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		if (lexer->c == ' ' || lexer->c == '\n')
			lexer_skip_whitespaces(lexer);
		if (ft_isalnum(lexer->c))
			return (lexer_collect_id(lexer));
		if (lexer->c == '-')
			return (lexer_collect_flag(lexer));
		if (lexer->c == '"')
			return (lexer_collect_string(lexer, '"'));
		if (lexer->c == 39)
			return (lexer_collect_string(lexer, 39));
		if (lexer->c == '|')
			return (lexer_advance_with_token(lexer, init_token(TOKEN_PIPE, lexer_get_current_char_as_string(lexer))));
		if (lexer->c == '<')
			return (lexer_collect_cmp(lexer, '<'));
		if (lexer->c == '>')
			return (lexer_collect_cmp(lexer, '>'));
	}
	return(NULL);
}

t_token	*lexer_advance_with_token(t_lexer *lexer, t_token *token)
{
	lexer_advance(lexer);
	return (token);
}

char	*lexer_get_current_char_as_string(t_lexer *lexer)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str[0] = lexer->c;
	return (str);
}

int main()
{
	t_lexer *lexer;
	t_token *token;

	lexer = init_lexer("<< ls -la | sleep 'hhh' ");
	token = (lexer_get_next_token(lexer));
	while (token != 0)
	{
		printf("TOKEN(%d, %s)\n", token->e_type, token->value);
		token = (lexer_get_next_token(lexer));
	}
}