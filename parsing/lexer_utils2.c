/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:35 by cjad              #+#    #+#             */
/*   Updated: 2022/05/22 16:04:39 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_token	*lexer_collect_id(t_lexer *lexer, t_lst **lst)
{
	char	*value;
	char	*temp;
	char	*s;

	value = ft_calloc(1, sizeof(char));
	while (ft_isnotspecial(lexer->c))
	{
		if (lexer->c == '"' || lexer->c == '\'')
			s = collection(lexer, lexer->c, lst);
		else if (lexer->c == '$')
			s = lexer_collect_dollar(lexer, lst);
		else
		{
			s = lexer_get_current_char_as_string(lexer);
			lexer_advance(lexer);
		}
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
	}
	return (lexer_id(lexer, value));
}

t_token	*lexer_collect_cmp(t_lexer *lexer, char c, t_lst **lst)
{
	lexer_advance(lexer);
	if (lexer->c == c)
	{
		lexer_advance(lexer);
		if (c == '<')
			return (init_token(TOKEN_HEREDOC, collect_string(lexer, lst)));
		else
			return (init_token(TOKEN_APPEND, collect_string(lexer, lst)));
	}
	else
	{
		if (c == '<' && lexer->c != '>')
			return (init_token(TOKEN_REDIR, collect_string(lexer, lst)));
		else if (c == '>' && lexer->c != '<')
			return (init_token(TOKEN_TRUNC, collect_string(lexer, lst)));
	}
	return (init_token(-1, NULL));
}

char	*collect_string(t_lexer *lexer, t_lst **lst)
{
	char	*value;
	char	*temp;
	char	*s;

	value = ft_calloc(1, sizeof(char));
	lexer_skip_whitespaces(lexer);
	while (ft_isnotspecial(lexer->c) || lexer->c == '$')
	{
		if (lexer->c == '$')
			s = lexer_collect_dollar(lexer, lst);
		else
			s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	return (value);
}

t_token	*lexer_id(t_lexer *lexer, char *value)
{
	if (lexer->command_flag == 0)
	{
		lexer->command_flag = 1;
		return (init_token(TOKEN_COMMAND, value));
	}
	else
		return (init_token(TOKEN_ARG, value));
}
