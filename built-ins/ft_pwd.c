/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:56:41 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/26 12:16:00 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_pwd(t_lst *lst)
{
	char	s1[1025];
	char	*s2;

	if (getcwd(s1, sizeof(s1)) != NULL)
	{
		s2 = ft_strdup(s1);
		return (s2);
	}
	return (get_env("PWD", lst));
}
