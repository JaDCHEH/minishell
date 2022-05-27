/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:17:50 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/24 14:33:05 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*quotes_utils(char *str)
{
	if (ft_strchr(str, '='))
		return (ft_strjoin(str, "\"\""));
	else
		return (str);
}

char	*add_quotes_str(char *str)
{
	char	*s_join;
	char	**splt;
	char	*tmp;

	splt = mini_split(str, '=');
	if (!splt[1])
	{
		free_double(splt);
		return (quotes_utils(str));
	}
	tmp = splt[1];
	splt[1] = ft_strjoin("\"", tmp);
	free(tmp);
	tmp = ft_strjoin(splt[1], "\"");
	s_join = ft_strjoin("=", tmp);
	str = ft_strjoin(splt[0], s_join);
	free_double(splt);
	free(s_join);
	free(tmp);
	return (str);
}

void	add_quotes_lst(t_lst **str)
{
	t_lst	*tmp;
	char	*st;

	tmp = *str;
	while (tmp)
	{
		st = tmp->content;
		tmp->content = add_quotes_str(st);
		free(st);
		tmp = tmp->next;
	}
}

int	str_checker(char *str)
{
	int	count;

	count = 1;
	if (!str)
		return (1);
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		ft_putstr_fd("export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	while (str[count] && str[count] != '=')
	{
		if ((!ft_isalnum(str[count]) && str[count] != '_' && str[count] != '='))
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		count++;
	}
	return (0);
}
