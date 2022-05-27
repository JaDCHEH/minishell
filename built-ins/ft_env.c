/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:12:23 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/19 14:36:19 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*strjoin_free(char *str1, char *str2, int i)
{
	char	*ret;

	ret = ft_strjoin(str1, str2);
	if (i == 1)
		free(str1);
	else if (i == 2)
		free(str2);
	return (ret);
}

char	*shlvl(char *str)
{
	int		shlvl;
	char	*tmp;
	char	*ret;

	str += 6;
	shlvl = ft_atoi(str);
	shlvl++;
	ret = strjoin_free("SHLVL=", ft_itoa(shlvl), 2);
	tmp = ret;
	return (ret);
}

char	*shlvl_with_quotes(char *str)
{
	char	*tmp;
	int		shlvl;

	str += 6;
	shlvl = ft_atoi(str);
	shlvl++;
	tmp = strjoin_free(ft_itoa(shlvl), "\"", 1);
	return (strjoin_free("SHLVL=\"", tmp, 2));
}

void	ft_env(char **str, t_lst **lst)
{
	int	i;

	i = 0;
	if (!(*lst) || !lst)
	{
		while (str[i + 1])
		{
			push(lst, str[i]);
			i++;
		}
	}
}
