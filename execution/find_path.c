/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:51:42 by cjad              #+#    #+#             */
/*   Updated: 2022/05/21 17:40:58 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_tab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	*check_path(char	**cmd, char **paths)
{
	char	*str;
	char	*pathtest;
	int		i;

	str = ft_strjoin("/", cmd[0]);
	pathtest = ft_strjoin(paths[0], str);
	i = 1;
	while (access(pathtest, F_OK) && paths[i])
	{
		free(pathtest);
		pathtest = ft_strjoin(paths[i], str);
		i++;
	}
	free_tab(paths);
	free(str);
	if (access(pathtest, F_OK))
	{
		free(pathtest);
		return (NULL);
	}
	return (pathtest);
}

char	*find_path(char	**envp, char **cmd)
{
	int		i;
	char	*str;
	char	**paths;
	int		a;

	i = 0;
	a = 0;
	str = NULL;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (envp[i])
		str = ft_strdup(&envp[i][5]);
	paths = ft_split(str, ':');
	if (str)
		free(str);
	if (paths)
		return (check_path(cmd, paths));
	else
		return (NULL);
}
