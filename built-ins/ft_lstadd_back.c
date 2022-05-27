/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 01:17:38 by ie-laabb          #+#    #+#             */
/*   Updated: 2022/05/13 17:13:28 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lst	*ft_lstnew(char *nb)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (0);
	node->content = ft_strdup(nb);
	node->next = NULL;
	return (node);
}

int	push(t_lst **stack, char *elem)
{
	t_lst	*new;

	if (!stack)
		return (0);
	new = ft_lstnew(elem);
	if (!new)
		return (0);
	ft_lstadd_back(stack, new);
	return (1);
}

t_lst	*ft_lstlast(t_lst	*lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (0);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
