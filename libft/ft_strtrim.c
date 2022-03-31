/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:48:58 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 11:36:54 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const	*s, char const	*trim)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (trim[j] != '\0')
		{
			if (s[i] == trim[j])
				break ;
			if (trim[j + 1] == '\0')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

static int	ft_end(char const	*s1, char const	*trim)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (trim[j] != '\0')
		{
			if (s1[i] == trim[j])
				break ;
			if (trim[j + 1] == '\0')
				return (i);
			j++;
		}
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*s;
	int		size;
	int		i;

	if (!s1)
		return (NULL);
	if (set[0] == '\0')
	{
		s = ft_strdup(s1);
		return (s);
	}
	size = ft_end(s1, set) - ft_start(s1, set) + 1;
	if (size < 0)
		size = 0;
	s = (char *) malloc (sizeof (char) * (size + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = s1[ft_start(s1, set) + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
