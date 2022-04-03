/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:18:55 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 11:39:26 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char	*s1, const char	*s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_strdup(const char	*s1)
{
	int		i;
	char	*scpy;

	i = ft_strlen(s1);
	scpy = (char *) malloc (sizeof (char) * (i + 1));
	if (!scpy)
		return (NULL);
	ft_strcpy(scpy, s1);
	return (scpy);
}
