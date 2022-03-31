#include "lexer.h"

t_token	*lexer_collect_flag(t_lexer *lexer)
{
	char	*value;
	char	*temp;
	char	*s;

	value = ft_calloc(2, sizeof(char));
	value[0] = '-';
	lexer_advance(lexer);
	while (ft_isalnum(lexer->c))
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	return (init_token(TOKEN_FLAG, value));
}

t_token	*lexer_collect_id(t_lexer *lexer)
{
	char	*value;
	char	*temp;
	char	*s;

	value = ft_calloc(1, sizeof(char));
	while (ft_isalnum(lexer->c))
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	return (init_token(TOKEN_ARG, value));
}

t_token	*lexer_collect_cmp(t_lexer *lexer, char c)
{
	lexer_advance(lexer);
	if (lexer->c == c)
	{
		lexer_advance(lexer);
		if (c == '<')
			return (init_token(TOKEN_DL_THAN, ft_strdup("<<")));
		else
			return (init_token(TOKEN_DG_THAN, ft_strdup(">>")));
	}
	else
	{
		if (c == '<')
			return (init_token(TOKEN_L_THAN, ft_strdup("<")));
		else
			return (init_token(TOKEN_G_THAN, ft_strdup(">")));
	}
}

t_token	*lexer_collect_string(t_lexer *lexer, char c)
{
	char	*value;
	char	*temp;
	char	*s;

	lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	while (lexer->c != c)
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return (init_token(TOKEN_ARG, value));
}