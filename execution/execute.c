/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:00:37 by cjad              #+#    #+#             */
/*   Updated: 2022/05/26 13:53:47 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	secend_func(t_parsing *pars, t_lst **lst, t_lst **lst1, int a)
{
	int	b;

	b = 0;
	if (!ft_strcmp(pars->arg[0], "cd") && !a)
		b = ft_cd(pars->arg[1], lst, lst1);
	else if (ft_strcmp(pars->arg[0], "env") == 0)
		print_lst(*lst, 0, pars);
	else
		b = secd_func_utils(pars, lst, lst1, a);
	return (-b);
}

int	first_func(t_parsing *pars, int i, t_lst *lst)
{
	char	*str1;

	if (!ft_strcmp(pars->arg[0], "exit") && !i)
		first_func_utils(pars);
	else if (ft_strcmp(pars->arg[0], "echo") == 0)
	{
		if (!ft_echo(pars))
			ft_putchar_fd('\n', pars->cmd_out);
	}
	else if (ft_strcmp(pars->arg[0], "pwd") == 0)
	{
		str1 = ft_pwd(lst);
		ft_putendl_fd(str1, pars->cmd_out);
		free(str1);
	}
	return (0);
}

int	find_redirs(int *f, t_parsing *parse)
{
	t_rdr	*tmp;

	tmp = parse->redir;
	f[0] = 0;
	f[1] = 1;
	while (tmp)
	{
		if (tmp->type == TOKEN_TRUNC || tmp->type == TOKEN_APPEND)
		{
			parse->cmd_out = tmp->fd;
			f[1] = tmp->fd;
		}
		if (tmp->type == TOKEN_REDIR || tmp->type == TOKEN_HEREDOC)
			f[0] = tmp->fd;
		tmp = tmp->next;
	}
	if (f[1] < 0 || f[0] < 0)
	{
		perror("");
		return (1);
	}
	return (0);
}

void	execution(t_parsing *tmp, t_id **id, t_lst **lst, t_lst **lst1)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (tmp && tmp->next && a >= 0)
	{
		i = 1;
		if (!(*id))
			(*id) = init_id(pipex(tmp, lst, lst1, i));
		else
			addback_id((*id), init_id(pipex(tmp, lst, lst1, i)));
		a = (*id)->id;
		tmp = tmp->next;
	}
	if (a >= 0)
	{
		if (!(*id))
			(*id) = init_id(single_cmd(tmp, lst, lst1, i));
		else
			addback_id((*id), init_id(single_cmd(tmp, lst, lst1, i)));
	}
}

void	execute(t_parsing *parse, t_lst **lst, t_lst **lst1)
{
	t_parsing	*tmp;
	t_id		*id;
	int			din;
	int			dout;

	tmp = parse;
	id = NULL;
	din = dup(0);
	dout = dup(1);
	check_cmd(1, 1);
	execution(tmp, &id, lst, lst1);
	wait_id(id);
	free_id(id);
	dup2(din, 0);
	dup2(dout, 1);
	close(dout);
	close(din);
}
