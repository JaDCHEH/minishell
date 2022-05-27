/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:40:17 by cjad              #+#    #+#             */
/*   Updated: 2022/05/26 10:09:13 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "lexer.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

typedef struct s_rdr
{
	int				heredoc;
	int				fd;
	int				type;
	struct s_rdr	*next;
}	t_rdr;

typedef struct s_parsing
{
	char				*cmd;
	char				**arg;
	int					argcount;
	int					cmd_out;
	t_rdr				*redir;
	int					flg;
	struct s_parsing	*next;
}	t_parsing;

int			here_id(int pid, int a);
int			multi_redir_error(char c);
int			check_general(char	*str);
int			check_pipes(char *str, int *i);
int			check_parse(char *str);
int			multi_redir_error(char c);
int			check_redir(char *str, char c, char a, int *i);
int			arg_count(t_token **token);
int			check_quotes(int s, int d);

/**********************************************************************/

char		*get_next_line(int fd);

/**********************************************************************/

void		quotes_counter(char *str, int *i, int *d, int *s);
void		addback(t_token **token, t_token *new);
void		addback_parse(t_parsing **parse, t_parsing *new);
void		free_parse(t_parsing *parse);
void		addback_redir(t_rdr **redir, t_rdr *new);
void		parse_filling(int *i, t_token	**token, t_parsing *parse);

/**********************************************************************/

t_parsing	*init_parsing(t_token **token);
t_rdr		*init_redir(char *value, int type);
t_parsing	*parsing(char	*str, t_lst **lst);

#endif