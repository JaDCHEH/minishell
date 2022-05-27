/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:13:55 by cjad              #+#    #+#             */
/*   Updated: 2022/05/27 11:26:05 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_builtins(t_parsing *parse)
{
	if (!ft_strcmp(parse->arg[0], "exit") || !ft_strcmp(parse->arg[0], "echo")
		|| !ft_strcmp(parse->arg[0], "pwd"))
		return (1);
	else if (!ft_strcmp(parse->arg[0], "cd") || !ft_strcmp(parse->arg[0], "env")
		|| !ft_strcmp(parse->arg[0], "export")
		|| (ft_strcmp(parse->arg[0], "unset") == 0))
		return (2);
	return (0);
}

static int	execute_builtins(t_parsing *parse, t_lst **lst, t_lst **lst1, int i)
{
	if (!ft_strcmp(parse->arg[0], "exit") || !ft_strcmp(parse->arg[0], "echo")
		|| !ft_strcmp(parse->arg[0], "pwd"))
		return (first_func(parse, i, *lst));
	else if (!ft_strcmp(parse->arg[0], "cd") || !ft_strcmp(parse->arg[0], "env")
		|| !ft_strcmp(parse->arg[0], "export")
		|| (ft_strcmp(parse->arg[0], "unset") == 0))
		return (secend_func(parse, lst, lst1, i));
	return (0);
}

pid_t	single_cmd(t_parsing *parse, t_lst **lst, t_lst **lst1, int i)
{
	pid_t	a;
	char	**env;
	int		f[2];

	if (!find_redirs(f, parse))
	{
		env = lst_to_char(*lst);
		if (f[0])
			dup2(f[0], 0);
		if (f[1])
			dup2(f[1], 1);
		parse->cmd_out = f[1];
		if (check_builtins(parse))
			a = execute_builtins(parse, lst, lst1, i);
		else
		{
			a = fork();
			if (a == 0)
				execute_command(env, parse->arg);
		}
		free_double(env);
		return (a);
	}
	return (-1);
}

int	first_func_utils(t_parsing *pars)
{
	printf("exit\n");
	if (pars->arg[1])
	{
		if (!ft_isdigit(pars->arg[1]))
		{
			ft_putstr_fd("Numeric argument required\n", 2);
			exit(255);
		}
		else if (pars->arg[2])
		{
			ft_putstr_fd("too many arguments\n", 2);
			g_ret = 1;
		}
		else
			exit(ft_atoi(pars->arg[1]));
	}
	return (0);
}

int	secd_func_utils(t_parsing *pars, t_lst **lst, t_lst **lst1, int a)
{
	int	i;
	int	b;

	b = 0;
	if (ft_strcmp(pars->arg[0], "export") == 0)
	{
		i = 0;
		while (pars->arg[i] && !a)
			b = ft_export(lst, lst1, pars->arg[i++]);
		if (!pars->arg[1])
			print_lst(*lst1, 1, pars);
	}
	else if (!ft_strcmp(pars->arg[0], "unset") && !a)
	{
		i = 1;
		while (pars->arg[i])
		{
			b = ft_unset(lst1, pars->arg[i]);
			b = ft_unset(lst, pars->arg[i]);
			i++;
		}
	}
	return (b);
}
