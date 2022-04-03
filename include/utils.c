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
	if (lexer->command_flag == 0)
	{
		lexer->command_flag = 1;
		return (init_token(TOKEN_COMMAND, value));
	}
	else
		return (init_token(TOKEN_ARG, value));
}

t_token	*lexer_collect_cmp(t_lexer *lexer, char c)
{
	lexer_advance(lexer);
	if (lexer->c == c)
	{
		lexer_advance(lexer);
		if (c == '<')
			return (init_token(TOKEN_HEREDOC, collect_string(lexer)));
		else
			return (init_token(TOKEN_APPEND, collect_string(lexer)));
	}
	else
	{
		if (c == '<')
			return (init_token(TOKEN_REDIR, collect_string(lexer)));
		else
			return (init_token(TOKEN_FILE, collect_string(lexer)));
	}
}

char *collect_string(t_lexer *lexer)
{
	char	*value;
	char	*temp;
	char	*s;

	lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	lexer_skip_whitespaces(lexer);
	while (ft_isalnum(lexer->c))
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	return(value);
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