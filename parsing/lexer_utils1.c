/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:36 by cjad              #+#    #+#             */
/*   Updated: 2022/05/22 16:01:21 by cjad             ###   ########.fr       */
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

int	ft_isnotspecial(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '\0'
		|| (c >= '\t' && c <= '\r') || c == ' ')
		return (0);
	return (1);
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
