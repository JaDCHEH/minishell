/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:54:28 by cjad              #+#    #+#             */
/*   Updated: 2022/05/27 13:51:47 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_pipes(char *str, int *i)
{
	int	a;

	a = 0;
	while ((str[a] >= '\t' && str[a] <= '\r') || str[a] == ' ')
		a++;
	if (str[a] == '|')
	{
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	if (str[*i] == '|')
	{
		while ((str[*i] >= '\t' && str[*i] <= '\r') || str[*i] == ' ')
			(*i)++;
		if (str[*i] == '|' || str[*i] == '\0')
		{
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	multi_redir_error(char c)
{
	ft_putstr_fd("unvalid redirection token `", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("`\n", 2);
	return (1);
}

int	check_redir(char *str, char c, char a, int *i)
{
	if (str[*i] == c)
	{
		if (str[(*i)] == c)
		{
			(*i)++;
			if (str[(*i)] && str[(*i)] == c)
			{
				(*i)++;
				if (str[(*i)] && (str[(*i)] == c || str[(*i)] == a))
					return (multi_redir_error(str[(*i)]));
			}
			else if (str[(*i)] && str[(*i)] == a)
				return (multi_redir_error(a));
		}
	}
	return (0);
}

void	quotes_counter(char *str, int *i, int *d, int *s)
{
	if (str[(*i)] == '"')
	{
		(*d)++;
		(*i)++;
		while (str[(*i)] && str[(*i)] != '"')
			(*i)++;
		if (str[(*i)] == '"')
			(*d)++;
	}
	if (str[(*i)] == '\'')
	{
		(*s)++;
		(*i)++;
		while (str[(*i)] && str[(*i)] != '\'')
			(*i)++;
		if (str[(*i)] == '\'')
			(*s)++;
	}
}

int	check_quotes(int s, int d)
{
	if ((s % 2))
	{
		ft_putstr_fd("Unclosed single quote `'`\n", 2);
		return (1);
	}
	if ((d % 2))
	{
		ft_putstr_fd("Unclosed double quote `\"`\n", 2);
		return (1);
	}
	return (0);
}
