/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:52:32 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/26 12:17:06 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	change_env(char *str, t_lst **lst, char *cnt)
{
	t_lst	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (ft_strcmp_v2(tmp, str) == 0)
		{
			free(tmp->content);
			tmp->content = ft_strdup(cnt);
			break ;
		}
		tmp = tmp->next;
	}
}

char	*ft_strchr_v2(const char *s, int c)
{
	int		i;
	char	mychar;

	i = 0;
	mychar = (char)c;
	while (s[i])
	{
		if (s[i] == mychar)
		{
			i++;
			return ((char *)s + i);
		}
		i++;
	}
	if (s[i] == mychar)
	{
		i++;
		return ((char *)s + i);
	}
	return (NULL);
}

void	swap_pwd(t_lst **lst)
{
	char	*pwd;
	char	*oldpwd;
	char	*join;

	oldpwd = get_env("PWD", *lst);
	join = ft_strjoin("OLDPWD=", oldpwd);
	free(oldpwd);
	change_env("OLDPWD", lst, join);
	pwd = ft_pwd(*lst);
	free(join);
	join = ft_strjoin("PWD=", pwd);
	change_env("PWD", lst, join);
	free(join);
	free(pwd);
}
