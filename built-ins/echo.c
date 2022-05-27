/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:04:51 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/21 19:25:26 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(t_parsing *pars)
{
	int	i;
	int	a;

	i = 1;
	if (ft_strcmp(pars->arg[i], "-n") == 0)
	{
		a = 1;
		i++;
	}
	else
		a = 0;
	while (i < pars->argcount)
	{
		if (pars->arg[i])
			ft_putstr_fd(pars->arg[i], pars->cmd_out);
		if ((i + 1) < pars->argcount)
			ft_putchar_fd(' ', pars->cmd_out);
		i++;
	}
	return (a);
}
