/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:18:30 by cjad              #+#    #+#             */
/*   Updated: 2022/05/26 12:20:29 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	child_process(int *fd, char **envp, t_parsing *parse)
{
	if (parse->cmd)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execute_command(envp, parse->arg);
	}
	else
		exit(0);
}

int	check_cmd(int a, int b)
{
	static int	c;

	if (b)
		c = a;
	return (c);
}

int	exec_pipe(t_parsing *parse, t_lst **lst, t_lst **lst1, int *fd)
{
	int		frk;
	char	**envp;

	envp = lst_to_char(*lst);
	if (!ft_strcmp(parse->arg[0], "exit") || !ft_strcmp(parse->arg[0], "echo")
		|| !ft_strcmp(parse->arg[0], "pwd"))
		frk = first_func(parse, parse->flg, *lst);
	else if (!ft_strcmp(parse->arg[0], "cd") || !ft_strcmp(parse->arg[0], "env")
		|| !ft_strcmp(parse->arg[0], "export")
		|| (ft_strcmp(parse->arg[0], "unset") == 0))
		frk = secend_func(parse, lst, lst1, parse->flg);
	else
	{
		frk = fork();
		if (frk == 0)
			child_process(fd, envp, parse);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	free_double(envp);
	return (frk);
}

pid_t	pipex(t_parsing	*parse, t_lst **lst, t_lst **lst1, int i)
{
	int		fd[2];
	int		f[2];

	pipe(fd);
	if (!find_redirs(f, parse))
	{
		parse->flg = i;
		if (f[0])
			dup2(f[0], 0);
		if (f[1] != 1)
		{
			close (fd[1]);
			fd[1] = f[1];
		}
		parse->cmd_out = fd[1];
		return (exec_pipe(parse, lst, lst1, fd));
	}
	return (-1);
}
