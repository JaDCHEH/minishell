/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:15:05 by cjad              #+#    #+#             */
/*   Updated: 2021/11/12 14:29:58 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	fill(char const	*s, char	*sub, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (i >= start && a < len)
		{
			sub[a] = s[i];
			a++;
		}
		i++;
	}
	sub[a] = '\0';
}

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	a;
	size_t	b;

	a = 0;
	i = 0;
	b = len + 1;
	if (!s)
		return (NULL);
	if (b > ft_strlen(s))
		b = ft_strlen(s) + 1;
	sub = (char *) malloc (sizeof (char) * b);
	if (!sub)
		return (NULL);
	fill(s, sub, start, len);
	return (sub);
}
