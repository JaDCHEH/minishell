/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:05:49 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/27 11:36:13 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	check_str(t_lst *str)
{
	int	i;

	i = 0;
	while (str)
	{
		while (str->content[i])
		{
			if (str->content[i] == '=')
				return (1);
			i++;
		}
		str = str->next;
	}
	return (0);
}

int	ft_strcmp_v2(t_lst *s1, char *s2)
{
	int	i;

	i = 0;
	if (check_str(s1) == 0)
		return (0);
	if (!s1 || !s2)
		return (-1);
	return (ft_strncmp(s1->content, s2, ft_strlen(s2)));
}

char	*get_env(char *var, t_lst *tmp)
{
	char	*ret;
	char	**splt;

	ret = NULL;
	while (tmp)
	{
		if (ft_strcmp_v2(tmp, var) == 0)
		{
			splt = mini_split(tmp->content, '=');
			ret = ft_strdup(splt[1]);
			free_double(splt);
		}
		tmp = tmp->next;
	}
	if (ret)
		return (ret);
	return (ft_strdup(""));
}

char	**mini_split(char *str, char c)
{
	char	**s;
	int		i;

	i = 0;
	s = malloc(sizeof(char *) * 3);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	s[0] = ft_strndup(str, i);
	s[1] = ft_strdup(&str[i + 1]);
	s[2] = NULL;
	return (s);
}
