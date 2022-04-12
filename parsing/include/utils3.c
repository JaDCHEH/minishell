/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:45:41 by cjad              #+#    #+#             */
/*   Updated: 2022/04/12 18:38:56 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	addback(t_token **token, t_token *new)
{
	t_token	*temp;

	temp = *token;
	
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	addback_parse(t_parsing **parse, t_parsing *new)
{
	t_parsing	*temp;

	temp = *parse;
	
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	arg_count(t_token **token)
{
	int		i;
	t_token	*tmp;

	tmp = *token;
	i = 0;
	while (tmp && tmp->e_type != TOKEN_PIPE)
	{
		if(tmp->e_type == TOKEN_ARG || tmp->e_type == TOKEN_COMMAND)
			i++;
		tmp = tmp->next;
	}
	return (i);
}