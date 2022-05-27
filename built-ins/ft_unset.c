/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:10:45 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/24 17:20:53 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset_utils(t_lst **lst, t_lst **lst1, char *str)
{
	t_lst	*tmp;
	t_lst	*temp;

	tmp = *lst;
	temp = *lst1;
	while (temp)
	{
		if (ft_strcmp_v2(temp, str) == 0)
		{
			tmp->next = temp->next;
			free(temp->content);
			free(temp);
			break ;
		}
		tmp = tmp->next;
		temp = temp->next;
	}
}

int	ft_unset(t_lst **lst, char *str)
{
	t_lst	*tmp;
	t_lst	*temp;

	tmp = *lst;
	temp = tmp->next;
	if (str)
	{
		if (str_checker(str) == 1)
			return (1);
		if (ft_strcmp_v2(*lst, str) == 0)
		{
			(*lst) = (*lst)->next;
			free(tmp->content);
			free(tmp);
			return (0);
		}
		ft_unset_utils(&tmp, &temp, str);
	}
	return (0);
}
