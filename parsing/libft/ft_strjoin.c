/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:39:42 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 11:39:39 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char	*s1, const char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

char	*ft_strjoin(char const	*s1, char const *s2)
{
	int		s1l;
	int		s2l;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	s = (char *) malloc (sizeof (char) * (s1l + s2l + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}
