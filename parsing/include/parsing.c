/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:23:15 by cjad              #+#    #+#             */
/*   Updated: 2022/04/12 19:56:14 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	initialisation(t_parsing *parse, t_token **token)
{
	parse->argcount = arg_count(token);
	parse->arg = ft_calloc(parse->argcount + 1, sizeof(char *));
	parse->append = NULL;
	parse->heredoc = NULL;
	parse->trunc = NULL;
	parse->redir = NULL;
	parse->next = NULL;
	return (0);
}

t_parsing	*init_parsing(t_token **token)
{
	t_parsing	*parse;
	int			i;

	parse = malloc (sizeof(t_parsing));
	i = initialisation(parse, token);
	while ((*token) && (*token)->e_type != TOKEN_PIPE)
	{
		if ((*token)->e_type == TOKEN_COMMAND)
			parse->cmd = (*token)->value;
		if ((*token)->e_type == TOKEN_COMMAND || (*token)->e_type == TOKEN_ARG)
		{
			parse->arg[i] = (*token)->value;
			i++;
		}
		if ((*token)->e_type == TOKEN_HEREDOC)
			parse->heredoc = (*token)->value;
		if ((*token)->e_type == TOKEN_APPEND)
			parse->append = (*token)->value;
		if ((*token)->e_type == TOKEN_REDIR)
			parse->trunc = (*token)->value;
		if ((*token)->e_type == TOKEN_FILE)
			parse->redir = (*token)->value;
		*token = (*token)->next;
	}
	if (*token && (*token)->e_type == TOKEN_PIPE)
		*token = (*token)->next;
	return (parse);
}

t_parsing	*parsing(char	*str)
{
	t_lexer		*lexer;
	t_token		(*token);
	t_parsing	*parse;

	lexer = init_lexer(str);
	lexer->command_flag = 0;
	token = lexer_get_next_token(lexer);
	while(lexer->c != '\0')
		addback(&token, lexer_get_next_token(lexer));
	parse = init_parsing(&token);
	while (token)
	{
		addback_parse(&parse, init_parsing(&token));
	}
	return (parse);
}
