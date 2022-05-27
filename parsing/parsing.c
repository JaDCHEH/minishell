/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:23:15 by cjad              #+#    #+#             */
/*   Updated: 2022/05/26 10:15:16 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_general(char	*str)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	s = 0;
	d = 0;
	while (str[i])
	{
		if (check_pipes(str, &i))
			return (1);
		if (check_redir(str, '<', '>', &i) || check_redir(str, '>', '<', &i))
			return (1);
		quotes_counter(str, &i, &d, &s);
		i++;
	}
	if (check_quotes(s, d))
		return (1);
	return (0);
}

int	check_final(t_parsing *pars)
{
	int			i;
	t_parsing	*tmp;
	t_rdr		*rdr;

	i = 0;
	tmp = pars;
	while (tmp)
	{
		rdr = pars->redir;
		while (rdr)
		{
			if (rdr->fd == -1 && rdr->heredoc)
				i = 1;
			rdr = rdr->next;
		}
		tmp = tmp->next;
	}
	return (i);
}

t_parsing	*parsing(char	*str, t_lst **lst)
{
	t_lexer		*lexer;
	t_token		*token;
	t_parsing	*parse;

	if (check_general(str))
		return (NULL);
	lexer = init_lexer(str);
	lexer->command_flag = 0;
	token = lexer_get_next_token(lexer, lst);
	while (lexer->c != '\0')
		addback(&token, lexer_get_next_token(lexer, lst));
	parse = init_parsing(&token);
	while (token)
	{
		addback_parse(&parse, init_parsing(&token));
	}
	free (lexer);
	if (check_final(parse))
	{
		free_parse(parse);
		return (NULL);
	}
	return (parse);
}
