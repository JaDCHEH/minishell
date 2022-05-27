/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:14 by cjad              #+#    #+#             */
/*   Updated: 2022/05/24 19:45:52 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	g_ret;

t_token	*lexer_get_next_token(t_lexer *lexer, t_lst **lst)
{
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->content))
	{
		lexer_skip_whitespaces(lexer);
		if (lexer->c == '<')
			return (lexer_collect_cmp(lexer, '<', lst));
		if (lexer->c == '>')
			return (lexer_collect_cmp(lexer, '>', lst));
		if (lexer->c == '|')
			return (lexer_advance_with_token(lexer, TOKEN_PIPE));
		if (ft_isnotspecial(lexer->c))
			return (lexer_collect_id(lexer, lst));
		if (lexer->c == '-')
			return (lexer_collect_flag(lexer));
		if (lexer->c == '=')
			return (lexer_advance_with_token(lexer, TOKEN_EQUALS));
	}
	return (NULL);
}
