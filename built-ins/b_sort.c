/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:19:02 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/21 17:12:17 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	b_sort(t_lst **lst)
{
	int		size;
	char	*str;
	t_lst	*tmp;

	size = ft_lstsize(lst);
	while (size > 0)
	{
		tmp = (*lst);
		while (tmp->next)
		{
			if (ft_strcmp(tmp->content, tmp->next->content) > 0)
			{
				str = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = str;
			}
			tmp = tmp->next;
		}
		size--;
	}
}
