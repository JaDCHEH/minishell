/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:45:41 by cjad              #+#    #+#             */
/*   Updated: 2022/05/22 18:37:48 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	initialisation(t_parsing *parse, t_token **token)
{
	parse->argcount = arg_count(token);
	parse->cmd = NULL;
	parse->arg = ft_calloc(parse->argcount + 1, sizeof(char *));
	parse->redir = NULL;
	parse->next = NULL;
	parse->cmd_out = 1;
	parse->flg = 0;
	return (0);
}

t_parsing	*init_parsing(t_token **token)
{
	t_parsing	*parse;
	int			i;
	t_token		*tmp;

	parse = malloc (sizeof(t_parsing));
	i = initialisation(parse, token);
	while ((*token) && (*token)->e_type != TOKEN_PIPE)
	{
		parse_filling(&i, token, parse);
		tmp = *token;
		*token = (*token)->next;
		free(tmp);
	}
	if (*token && (*token)->e_type == TOKEN_PIPE)
	{
		free((*token)->value);
		tmp = (*token);
		*token = (*token)->next;
		free(tmp);
	}
	return (parse);
}

void	addback_parse(t_parsing **parse, t_parsing *new)
{
	t_parsing	*temp;

	temp = *parse;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	addback(t_token **token, t_token *new)
{
	t_token	*temp;

	temp = *token;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
