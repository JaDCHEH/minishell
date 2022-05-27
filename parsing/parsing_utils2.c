/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:58:18 by cjad              #+#    #+#             */
/*   Updated: 2022/05/19 13:07:54 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	addback_redir(t_rdr **redir, t_rdr *new)
{
	t_rdr	*temp;

	temp = *redir;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	parse_filling(int *i, t_token	**token, t_parsing *parse)
{
	char	*value;
	int		type;

	value = (*token)->value;
	type = (*token)->e_type;
	if (type == TOKEN_COMMAND)
		parse->cmd = value;
	if (type == TOKEN_COMMAND || type == TOKEN_ARG)
	{
		parse->arg[(*i)] = value;
		(*i)++;
	}
	if (type == TOKEN_HEREDOC || type == TOKEN_APPEND
		|| type == TOKEN_REDIR || type == TOKEN_TRUNC)
	{
		if (!parse->redir)
			parse->redir = init_redir(value, type);
		else
			addback_redir(&parse->redir, init_redir(value, type));
	}
}

int	arg_count(t_token **token)
{
	int		i;
	t_token	*tmp;

	tmp = *token;
	i = 0;
	while (tmp && tmp->e_type != TOKEN_PIPE)
	{
		if (tmp->e_type == TOKEN_ARG || tmp->e_type == TOKEN_COMMAND)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
