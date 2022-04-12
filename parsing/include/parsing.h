/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:40:17 by cjad              #+#    #+#             */
/*   Updated: 2022/04/12 18:40:24 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "lexer.h"

typedef struct	s_parsing
{
	char				*cmd;
	char				**arg;
	int					argcount;
	char				*redir;
	char				*append;
	char				*trunc;
	char				*heredoc;
	struct s_parsing	*next;
}	t_parsing;

t_parsing	*parsing(char	*str);
void		addback(t_token **token, t_token *new);
void		addback_parse(t_parsing **parse, t_parsing *new);
int			arg_count(t_token **token);

#endif