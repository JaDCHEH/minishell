/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:36 by cjad              #+#    #+#             */
/*   Updated: 2022/04/12 17:38:28 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	token->next = NULL;
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

t_token	*lexer_advance_with_token(t_lexer *lexer, int type)
{
	char	*value;

	value = lexer_get_current_char_as_string(lexer);
	lexer_advance(lexer);
	return (init_token(type, value));
}

char	*lexer_collect_dollar(t_lexer *lexer, int i)
{
	char	*value;
	char	*s;
	char	*temp;
	
	lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	while (ft_isnotspecial(lexer->c))
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		if (!ft_isnotspecial(lexer->content[lexer->i + 1]) && i)
			break ;
		lexer_advance(lexer);
	}
	temp = getenv(value);
	free (value);
	value = ft_strdup(temp);
	return (value);
}

int	ft_isnotspecial(char c)
{
	if (c == '<' || c == '>' || c == '$' || c == '|' || c == '\0'
		|| (c >= '\t' && c <= '\r') || c == ' ' || c == '\'' || c == '"' )
			return (0);
	return (1);
}