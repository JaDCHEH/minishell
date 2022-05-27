/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:02:29 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/26 09:45:26 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_lst(t_lst *lst, int i, t_parsing *pars)
{
	if (i == 0)
	{
		while (lst)
		{
			ft_putendl_fd(lst->content, pars->cmd_out);
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			ft_putstr_fd("declare -x ", pars->cmd_out);
			ft_putendl_fd(lst->content, pars->cmd_out);
			lst = lst->next;
		}
	}
}

void	tolowes(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return ;
	while (c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			c[i] += 32;
		i++;
	}
}

void	free_parse(t_parsing *parse)
{
	t_parsing	*temp;
	t_rdr		*tmp;

	while (parse)
	{
		temp = parse;
		free_double(parse->arg);
		while (parse->redir)
		{
			tmp = parse->redir;
			if (parse->redir->fd > 0)
				close(parse->redir->fd);
			parse->redir = parse->redir->next;
			free(tmp);
		}
		parse = parse->next;
		free(temp);
	}
}

void	sig_handle(int sig)
{
	if (here_id(0, 0) != 0 && sig == SIGINT)
	{
		ft_putendl_fd(NULL, 1);
		kill(here_id(0, 0), SIGTERM);
		g_ret = 1;
	}
	else if (sig == SIGINT)
	{
		if (check_cmd(0, 0) == 0)
		{
			ft_putstr_fd("\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			g_ret = 1;
		}
		else
		{
			ft_putendl_fd(NULL, 1);
			g_ret = 130;
		}
	}
}

void	sigquithandler(int sig)
{
	if (sig == SIGQUIT)
	{
		if (here_id(0, 0))
		{
		}
		else if (check_cmd(0, 0) == 1)
		{
			g_ret = 131;
			ft_putstr_fd("Quit: 3\n", 1);
		}
		else
		{
			rl_on_new_line();
			rl_redisplay();
		}
	}
}
