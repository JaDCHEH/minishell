/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 00:47:16 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/26 13:49:09 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_cd_utils(char *str, t_lst *lst, char *env)
{
	int	re;

	re = 0;
	if (ft_strcmp(str, "~") == 0)
	{
		env = get_env("HOME", lst);
		if (chdir(env) == -1)
		{
			re = 1;
			perror(NULL);
		}
		free(env);
	}
	else
	{
		if (chdir(str) == -1)
		{
			perror(NULL);
			re = 1;
		}
	}
	return (re);
}

int	ft_cd_helper(char *env, t_lst *lst, char *str)
{
	int	i;
	int	re;

	re = 0;
	i = 0;
	if (ft_strncmp(&str[i], "~/", 2) == 0)
	{
		env = get_env("HOME", lst);
		if (chdir(env) == -1)
		{
			re = 1;
			perror(NULL);
		}
		else if (chdir(ft_strchr_v2(str, '/')) == -1)
		{
			re = 1;
			perror(NULL);
		}
		free(env);
	}
	else
		re = ft_cd_utils(str, lst, env);
	return (re);
}

int	cd_tiret(t_lst *lst)
{
	char	*env;
	int		re;

	re = 0;
	env = get_env("OLDPWD", lst);
	if (chdir(env) == -1)
	{
		perror(NULL);
		re = 1;
		return (re);
	}
	ft_putendl_fd(env, 1);
	free(env);
	return (re);
}

int	ft_cd(char *str, t_lst **lst, t_lst **lst1)
{
	char	*env;
	int		re;

	re = 0;
	env = NULL;
	if (str == NULL)
	{
		env = get_env("HOME", *lst);
		if (chdir(env) == -1)
		{
			re = 1;
			perror(NULL);
		}
		free(env);
	}
	else if (ft_strcmp(str, "-") == 0)
		re = cd_tiret(*lst);
	else
		ft_cd_helper(env, *lst, str);
	swap_pwd(lst);
	swap_pwd(lst1);
	return (re);
}
