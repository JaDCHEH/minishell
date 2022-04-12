/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:30 by cjad              #+#    #+#             */
/*   Updated: 2022/04/12 17:49:03 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "../libft/libft.h"

typedef struct s_lexer
{
	char			c;
	unsigned int	i;
	char			*content;
	int				command_flag;
}	t_lexer;

typedef struct s_token
{
	enum
	{
		TOKEN_REDIR,
		TOKEN_HEREDOC,
		TOKEN_COMMAND,
		TOKEN_FLAG,
		TOKEN_ARG,
		TOKEN_FILE,
		TOKEN_APPEND,
		TOKEN_EQUALS,
		TOKEN_PIPE,
	} e_type;
	char			*value;
	struct s_token	*next;
}	t_token;

typedef struct s_token_list
{
	t_token				*token;
	struct s_token_list	*next;
}	t_token_list;

typedef struct s_list
{
	t_token_list	*top;
}	t_list;

t_lexer	*init_lexer(char *content);
t_token	*init_token(int e_type, char *value);
t_token	*lexer_get_next_token(t_lexer *lexer);
t_token	*lexer_collect_flag(t_lexer *lexer);
t_token	*lexer_collect_id(t_lexer *lexer);
t_token	*lexer_collect_cmp(t_lexer *lexer, char c);
t_token	*lexer_collect_string(t_lexer *lexer, char c);
t_token	*lexer_advance_with_token(t_lexer *lexer, int type);
char	*collect_string(t_lexer *lexer);
char	*lexer_collect_dollar(t_lexer *lexer, int i);
void	lexer_advance(t_lexer *lexer);
void	lexer_skip_whitespaces(t_lexer	*lexer);
char	*lexer_get_current_char_as_string(t_lexer *lexer);
int		ft_isnotspecial(char c);

#endif