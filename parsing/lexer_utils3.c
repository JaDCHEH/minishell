/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:12:33 by cjad              #+#    #+#             */
/*   Updated: 2022/05/27 11:29:07 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lexer_get_current_char_as_string(t_lexer *lexer)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	str[0] = lexer->c;
	if (lexer->c == '|')
		lexer->command_flag = 0;
	return (str);
}

void	lexer_skip_whitespaces(t_lexer	*lexer)
{
	while ((lexer->c >= '\t' && lexer->c <= '\r') || lexer->c == ' ')
		lexer_advance(lexer);
}

char	*advance_quest(t_lexer *lexer, int i)
{
	lexer_advance(lexer);
	return (ft_itoa(i));
}

char	*lexer_collect_dollar(t_lexer *lexer, t_lst **lst)
{
	char	*value;
	char	*s;
	char	*temp;

	lexer_advance(lexer);
	if (lexer->c == ' ' || lexer->c == '\0' || lexer->c == '$')
	{
		return (ft_strdup("$"));
	}
	if (lexer->c == '?')
		return (advance_quest(lexer, g_ret));
	value = ft_calloc(1, sizeof(char));
	while (ft_isnotspecial(lexer->c) && lexer->c != '$' && lexer->c != '\''
		&& lexer->c != '"')
	{
		s = lexer_get_current_char_as_string(lexer);
		temp = ft_strjoin(value, s);
		free(s);
		free(value);
		value = temp;
		lexer_advance(lexer);
	}
	temp = get_env(value, *lst);
	free (value);
	return (temp);
}

char	*collection(t_lexer *lexer, char c, t_lst **lst)
{
	char	*value;
	char	*temp;
	char	*s;

	lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	while (lexer->c != c && lexer->c != '\0')
	{
		if (lexer->c == '$' && c == '"')
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
	if (lexer->c == c)
		lexer_advance(lexer);
	return (value);
}
