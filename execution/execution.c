/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:23:54 by cjad              #+#    #+#             */
/*   Updated: 2022/05/25 19:42:32 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lstsize(t_lst **lst)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**lst_to_char(t_lst *lst)
{
	char	**env;
	int		i;

	env = malloc(sizeof(char *) * (ft_lstsize(&lst) + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (lst)
	{
		env[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	env[i] = NULL;
	return (env);
}

int	absolute_path(char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (cmd[i] == '/')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*check_absolute(char *path)
{
	if (access(path, F_OK))
		return (NULL);
	return (path);
}

void	execute_command(char	**envp, char	**cmd)
{
	char	*path;

	if (cmd[0])
	{
		if (absolute_path(cmd[0]))
			path = check_absolute(cmd[0]);
		else
			path = find_path(envp, cmd);
		if (path)
		{
			execve(path, cmd, envp);
		}
		else
		{
			ft_putstr_fd("`", 2);
			ft_putstr_fd(cmd[0], 2);
			ft_putstr_fd("` No such file or directory\n", 2);
			exit(127);
		}
	}
	else
		exit(0);
}
