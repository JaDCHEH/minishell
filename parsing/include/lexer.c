/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:14 by cjad              #+#    #+#             */
/*   Updated: 2022/04/05 22:04:23 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

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
		if (lexer->c == '<')
			return (lexer_collect_cmp(lexer, '<'));
		if (lexer->c == '>')
			return (lexer_collect_cmp(lexer, '>'));
		if (lexer->c == '|')
			return (lexer_advance_with_token(lexer, TOKEN_PIPE));
		if (ft_isalnum(lexer->c))
			return (lexer_collect_id(lexer));
		if (lexer->c == '-')
			return (lexer_collect_flag(lexer));
		if (lexer->c == '=')
			return (lexer_advance_with_token(lexer, TOKEN_EQUALS));
		if (lexer->c == '"')
			return (lexer_collect_string(lexer, '"'));
		if (lexer->c == 39)
			return (lexer_collect_string(lexer, 39));
		if (lexer->c == '$')
			return (init_token(TOKEN_ARG, lexer_collect_dollar(lexer, 0)));
	}
	return (NULL);
}

char	*lexer_get_current_char_as_string(t_lexer *lexer)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str[0] = lexer->c;
	if (lexer->c == '|')
		lexer->command_flag = 0;
	return (str);
}

int	main()
{
	t_lexer			*lexer;
	t_token			*token;

	lexer = init_lexer("$PATH=");
	lexer->command_flag = 0;
	token = lexer_get_next_token(lexer);
	while (token != 0)
	{
		printf("TOKEN(%d, %s)\n", token->e_type, token->value);
		token = (lexer_get_next_token(lexer));
	}
}