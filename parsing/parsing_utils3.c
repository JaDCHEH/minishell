/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ie-laabb <ie-laabb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:28:24 by cjad              #+#    #+#             */
/*   Updated: 2022/05/26 14:22:40 by ie-laabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exec_heredoc(int *fd, char	*limiter)
{
	char	*str;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	rl_clear_history();
	close(fd[0]);
	str = readline("> ");
	while (str)
	{
		if (!ft_strcmp(limiter, str))
			break ;
		ft_putendl_fd(str, fd[1]);
		free(str);
		str = readline("> ");
	}
	free(str);
	exit(0);
}

int	here_id(int pid, int a)
{
	static int	id;

	if (a)
		id = pid;
	return (id);
}

int	heredoc(char	*limiter)
{
	int		fd[2];
	int		id;
	int		status;

	if (limiter[0])
	{
		pipe(fd);
		id = fork();
		if (!id)
			exec_heredoc(fd, limiter);
		here_id(id, 1);
		waitpid(id, &status, 0);
		if (WIFSIGNALED(status))
		{
			close(fd[1]);
			close(fd[0]);
			here_id(0, 0);
			return (-1);
		}
		here_id(0, 0);
		close(fd[1]);
		return (fd[0]);
	}
	ft_putendl_fd("syntax error near unexpected token `newline'", 2);
	return (-1);
}

t_rdr	*init_redir(char *value, int type)
{
	t_rdr	*new;

	new = ft_calloc(1, sizeof(t_rdr));
	new->heredoc = 0;
	if (type == TOKEN_REDIR)
		new->fd = open(value, O_RDONLY);
	if (type == TOKEN_HEREDOC)
	{
		new->heredoc = 1;
		new->fd = heredoc(value);
	}
	if (type == TOKEN_APPEND)
		new->fd = open(value, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (type == TOKEN_TRUNC)
		new->fd = open(value, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	new->type = type;
	new->next = NULL;
	free(value);
	return (new);
}
