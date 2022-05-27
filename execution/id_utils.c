/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:42:53 by cjad              #+#    #+#             */
/*   Updated: 2022/05/25 19:25:13 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_id	*init_id(pid_t id)
{
	t_id	*new;

	new = malloc(sizeof(t_id));
	new->id = id;
	new->next = NULL;
	return (new);
}

void	addback_id(t_id *lst, t_id *new)
{
	t_id	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_id(t_id *id)
{
	t_id	*tmp;

	while (id)
	{
		tmp = id;
		id = id->next;
		free(tmp);
	}
}

void	wait_id(t_id *id)
{
	t_id	*tmp;
	int		status;

	tmp = id;
	while (tmp)
	{
		if (tmp->id > 0)
		{
			waitpid(tmp->id, &status, 0);
			if (!WIFSIGNALED(status))
				g_ret = WEXITSTATUS(status);
		}
		else
			g_ret = (unsigned char) -(tmp->id);
		tmp = tmp->next;
	}
	check_cmd(0, 1);
}
