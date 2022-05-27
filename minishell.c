/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:32:25 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/26 14:06:37 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_readline(t_lst **lst, t_lst **lst1, t_parsing *pars)
{
	if (pars)
		execute(pars, lst, lst1);
}

void	minishell_helper(char *str, char **env, t_lst **lst, t_lst **lst1)
{
	t_parsing	*pars;
	int			i;

	i = 0;
	add_history(str);
	if (i == 0)
	{
		ft_env(env, lst1);
		ft_env(env, lst);
		i = 1;
	}
	pars = parsing(str, lst);
	if (pars && pars->arg)
		tolowes(pars->arg[0]);
	check_readline(lst, lst1, pars);
	free_parse(pars);
}

void	minishell(char **env)
{
	char	*str;
	t_lst	*lst;
	t_lst	*lst1;

	lst = NULL;
	lst1 = NULL;
	while (1)
	{
		str = readline("minishell > ");
		if (str == NULL)
		{
			printf("exit\n");
			exit(0);
		}
		if (str[0])
			minishell_helper(str, env, &lst, &lst1);
		free(str);
	}
}

int	main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;
	g_ret = 0;
	signal(SIGINT, sig_handle);
	signal(SIGQUIT, sigquithandler);
	minishell(env);
}
