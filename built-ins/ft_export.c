/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:21:42 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/24 15:34:03 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	my_strchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	check_lst2(t_lst **tmp, char *str, int i)
{
	if (my_strchr(str) == 0)
	{
		free((*tmp)->content);
		if (i == 0)
			(*tmp)->content = add_quotes_str(str);
		else
			(*tmp)->content = ft_strdup(str);
	}
}

int	check_lst(char *str, t_lst **lst, int i)
{
	char	**split;
	char	**s;
	t_lst	*tmp;

	tmp = *lst;
	split = mini_split(str, '=');
	while (tmp)
	{
		s = mini_split(tmp->content, '=');
		if (ft_strcmp(s[0], split[0]) == 0)
		{
			check_lst2(&tmp, str, i);
			free_double(split);
			free_double(s);
			return (1);
		}
		tmp = tmp->next;
		free_double(s);
	}
	free_double(split);
	return (0);
}

void	export_helper(t_lst **lst, t_lst **lst1, char *str1)
{
	char	*s;

	if (check_lst(str1, lst1, 0) == 0)
	{
		if (ft_strchr(str1, '='))
		{
			s = add_quotes_str(str1);
			push(lst1, s);
			free(s);
		}
		else
			push(lst1, str1);
	}
	if (check_lst(str1, lst, 1) == 0)
	{
		if (ft_strchr(str1, '=') != NULL)
			push(lst, str1);
	}
}

int	ft_export(t_lst **lst, t_lst **lst1, char *str1)
{
	static int	i;
	int			re;

	re = 0;
	if (i == 0)
	{
		add_quotes_lst(lst1);
		i = 1;
	}
	if (str1 && ft_strcmp(str1, "export"))
	{
		i = 1;
		re = str_checker(str1);
		if (re != 1)
			export_helper(lst, lst1, str1);
	}
	b_sort(lst1);
	return (re);
}
